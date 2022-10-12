#include "ServerBase.h"

ServerBase::ServerBase()
{
	result = WSAStartup(MAKEWORD(2, 2), &wsaData);	//linker error
	lSocket = new ServerSocket();
	cSocket = new ClientSocket();
	accountManager = new AccountManager();
	gameManager = new BaseballGameManager(cSocket);
	ZeroMemory(addr, sizeof(addr));
	//menuHandler = nullptr;
	loopFlag = true;
}

ServerBase::~ServerBase()
{
	if (gameManager != nullptr) delete gameManager;
	if (cSocket != nullptr) delete cSocket;
	if (lSocket != nullptr) delete lSocket;
	//if (menuHandler != nullptr) delete menuHandler;
	WSACleanup();
}

void ServerBase::Run()	//run server
{
	int index = 0;
	if (!Initialization()) 
	{
		std::cout << "Server Initialization Failed" << std::endl;
		return;
	}
	while (1) 
	{
		Connect();
		while (loopFlag) 
		{
			cSocket->RecvBoolPacket();	//get menu selection
			if (cSocket->GetProtocol() != DISCON && cSocket->GetFlag() == false) continue;	//exception: invalid data
			ServiceSwitch(cSocket);
		}
		Disconnect();
	}
}

bool ServerBase::Initialization()	//server initialization
{
	result = WSAStartup(MAKEWORD(2, 2), &wsaData);	//linker error

	//WSA startup validation
	if (IsWSAStartFail())
	{
		std::cout << "WSAStartup() Error" << std::endl;
		return false;
	}

	//listen socket validation
	if (lSocket->IsInvalidSock())
	{
		std::cout << "socket() error" << std::endl;
		return false;
	}

	//socket binding state validation
	lSocket->BindSocket();
	if (lSocket->IsUnbindedSocket())
	{
		std::cout << "bind() error" << std::endl;
		return false;
	}

	//listen socket state validation
	lSocket->ListenToConnection();
	if (lSocket->IsWrongConnection())
	{
		std::cout << "listen() error" << std::endl;
		return false;
	}
	return true;
}

bool ServerBase::IsWSAStartFail()	//validate initialization
{
	return result != 0;
}

void ServerBase::ServiceSwitch(ClientSocket*& socket)
{
	cSocket->SetFlag(false);
	switch (socket->GetProtocol())
	{
		case REG:
			Registration();
			break;
		case LIN:
			if (LogIn() == false)	//exception : login fail
			{
				break;
			}
			if(ReadyToPlayGame() == false)
			{
				break;
			}
			//game start if login success
			gameManager->Run();
			//
			break;
		case EXIT:
			SendDisconnectionPacket();
			break;
	}
}

void ServerBase::Registration()
{
	ReadyForRegistration();
	cSocket->RecvAccPacket();
	SendRegistrationResult();
}

void ServerBase::ReadyForRegistration()
{
	//cSocket->SetProtocol(REGRDY);
	//cSocket->SetFlag(true);
	cSocket->SendBoolPacket(REGRDY);
	//cSocket->ClearTempDatas();
}

void ServerBase::SendRegistrationResult()
{	
	if (cSocket->GetProtocol() != REG) {
		//cSocket->SetProtocol(REGFAIL);
		//cSocket->SetFlag(false);
		cSocket->SendBoolPacket(REGFAIL);
		return;
	}
	accountManager->Registration(cSocket->GetAccountData());
	//cSocket->SetProtocol(REGSUC);
	//cSocket->SetFlag(true);
	cSocket->SendBoolPacket(REGSUC);
}

bool ServerBase::LogIn()
{
	ReadyForLogIn();
	cSocket->RecvAccPacket();
	return SendLogInResult();
}

void ServerBase::ReadyForLogIn()
{
	//cSocket->SetProtocol(LINRDY);
	//cSocket->SetFlag(true);
	cSocket->SendBoolPacket(LINRDY);
	cSocket->ClearTempDatas();
}

bool ServerBase::SendLogInResult()
{
	if (accountManager->LogIn(cSocket->GetAccountData()) == false)
	{
		//cSocket->SetProtocol(LINFAIL);
		//cSocket->SetFlag(true);
		cSocket->SendBoolPacket(LINFAIL);
		cSocket->ClearTempDatas();
		return false;
	}
	//cSocket->SetProtocol(LINSUC);
	//cSocket->SetFlag(true);
	cSocket->SendBoolPacket(LINSUC);
	return true;
}

bool ServerBase::ReadyToPlayGame()
{
	cSocket->RecvBoolPacket();
	if (cSocket->GetFlag() == false || cSocket->GetProtocol() != EXEGAME)
	{
		return false;
	}
	//cSocket->SetProtocol(GAMERDY);
	//cSocket->SetFlag(true);
	cSocket->SendBoolPacket(GAMERDY);
	//cSocket->SetFlag(false);
	return true;
}

void ServerBase::SendDisconnectionPacket()
{	
	//cSocket->SetProtocol(DISCON);
	//cSocket->SetFlag(true);
	cSocket->SendBoolPacket(DISCON);
	//cSocket->RecvBoolPacket();
	loopFlag = false;
}

void ServerBase::Connect()
{
	cSocket->AcceptConnection(lSocket->GetSocket());
	if (cSocket->IsFailToAccept())
	{
		std::cout << "accept() error" << std::endl;
		return;
	}
	inet_ntop(AF_INET, &cSocket->GetSockAddr()->sin_addr, addr, sizeof(addr));
	std::cout << "Connected : ip = " << addr << ", port = " << ntohs(cSocket->GetSockAddr()->sin_port) << std::endl;
}

void ServerBase::Disconnect()
{
	std::cout << "Disconnected : ip = " << addr << ", port = " << ntohs(cSocket->GetSockAddr()->sin_port) << std::endl;
	cSocket->~ClientSocket();	//call destructor to destroy object without release memory
	loopFlag = true;
}

void ServerBase::ShutdownServer()
{
	if (lSocket != nullptr) delete lSocket;
	if (cSocket != nullptr) delete cSocket;
	if (accountManager != nullptr) delete accountManager;
}
