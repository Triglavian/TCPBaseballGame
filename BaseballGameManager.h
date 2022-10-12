#pragma once
#include <sstream>
#include "Protocol.h"
#include "ClientSocket.h"
#include "NumberGenerator.h"
#include "NumberComparer.h"


class ClientSocket;

class BaseballGameManager
{
public:
	BaseballGameManager();
	BaseballGameManager(ClientSocket* socket);
	~BaseballGameManager();
	void Run();
	void ProtocolSwitch(const Protocol& protocol);
private:
	ClientSocket* _socket;
	NumberGenerator* numberGeneragor;
	NumberComparer* comparer;
	GameReport report;
	bool gameLoop;
	void PlayGame();
	void QuitGame();
	void GenerateNotSameNumbers();
	bool GetNumbersFromClient(std::array<int, 3>& clientNums);
	void SetNumbersFromString(const std::string& str, std::array<int, 3>& nums);
	bool IsInvalidData(const std::array<int, 3>& clientNums);
	void SendResult(const Protocol& protocol);
	void AddTryCount();
	void ResetTryCount();
	void SendTryCount();
	void SendGameReport();
};

