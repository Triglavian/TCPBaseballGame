#include "BaseballGameManager.h"

BaseballGameManager::BaseballGameManager()
{
	_socket = nullptr;
	numberGeneragor = nullptr;
	comparer = nullptr;
	gameLoop = true;
}

BaseballGameManager::BaseballGameManager(ClientSocket* socket)
{
	_socket = socket;
	numberGeneragor = new NumberGenerator();
	comparer = new NumberComparer();
	gameLoop = true;
}

BaseballGameManager::~BaseballGameManager()
{
	_socket = nullptr;
	if (numberGeneragor != nullptr) delete numberGeneragor;
	if (comparer != nullptr) delete comparer;
}

void BaseballGameManager::Run()
{
	while (gameLoop) //escape if get QUIT protocol
	{
		_socket->RecvBoolPacket();
		ProtocolSwitch(_socket->GetProtocol());
	}
	gameLoop = true;
}

void BaseballGameManager::ProtocolSwitch(const Protocol& protocol)
{
	switch (protocol) 
	{
		case PLAY:
			PlayGame();
			break;
		case QUIT:
			QuitGame();
			SendGameReport();
			break;
	}
}

void BaseballGameManager::PlayGame()
{
	_socket->SendBoolPacket(PLAYRDY);

	//create numbers
	GenerateNotSameNumbers();
	std::array<int, 3> clientNums;	//numbers received from client
	while (true) //escape if all numbers are same
	{
		AddTryCount();
		GetNumbersFromClient(clientNums);
		if (comparer->CompareNumbers(clientNums)) break;	//exception : all numbers at same index are same
		SendResult(RETNOUT);
	}
	report.UpdateReport();
	SendResult(RETOUT);
	SendTryCount();
	ResetTryCount();
}

void BaseballGameManager::QuitGame()
{
	_socket->SendBoolPacket(QUITRDY);
	gameLoop = false;
}

void BaseballGameManager::GenerateNotSameNumbers()
{
	numberGeneragor->GenerateNumbers(3);
	comparer->SetGeneratedNumbers(numberGeneragor->GetNumbers());
}

bool BaseballGameManager::GetNumbersFromClient(std::array<int, 3>& clientNums)
{
	_socket->RecvStrPacket();
	if (_socket->GetProtocol() != INNUM || _socket->GetStr()[0] == '\n')	//exception : invalid packet or empty data
	{
		return false;
	}
	SetNumbersFromString(_socket->GetStr(), clientNums);
	if (IsInvalidData(clientNums)) return false;	//exception : invalid or uncomplite data 
	return true;
}

void BaseballGameManager::SetNumbersFromString(const std::string& str, std::array<int, 3>& nums)
{
	std::istringstream instream(_socket->GetStr());	//input string stream
	std::string token;	//tokenized string
	for (int i = 0; i < 3; i++)	
	{
		instream >> token;	//tokenize input string stream by space and set to token
		nums[i] = token[0] - '0';	//set tokenized string to array as int
	}
}

bool BaseballGameManager::IsInvalidData(const std::array<int, 3>& clientNums)
{
	for (int i = 0; i < 3; i++) 
	{
		if (clientNums[i] < 0 || clientNums[i] > 9) return true;	//exception : negative number remain, invalid or uncomplite data received
	}
	return false;
}

void BaseballGameManager::SendResult(const Protocol& protocol)
{
	_socket->SetProtocol(protocol);
	_socket->SetResult(comparer->GetResult());
	_socket->SendResultPacket();
}

void BaseballGameManager::AddTryCount()
{
	report.tryCount++;
}

void BaseballGameManager::ResetTryCount()
{
	report.tryCount = 0;
}

void BaseballGameManager::SendTryCount()
{
	_socket->SetProtocol(SENDCNT);
	_socket->SetNum(report.tryCount);
	_socket->SendIntPacket();
}

void BaseballGameManager::SendGameReport()
{
	_socket->SetProtocol(SENDREP);
	_socket->SendReportPacket(report);
}
