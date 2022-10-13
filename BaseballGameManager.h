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
	BaseballGameManager();	//do not use
	BaseballGameManager(ClientSocket* socket);	//use this
	~BaseballGameManager();
	void Run();			//game base
private:
	ClientSocket* _socket;				//receive from serverbase, do not create new obj
	NumberGenerator* numberGeneragor;
	NumberComparer* comparer;
	GameReport report;
	bool gameLoop;
	void ProtocolSwitch(const Protocol& protocol);	//received protocol switch
	void PlayGame();				//start baseball game
	void QuitGame();				//send quit request response packet and breaking inf loop
	void GenerateNotSameNumbers();	//generate seperate 3 numbers
	bool GetNumbersFromClient(std::array<int, 3>& clientNums);	//receive numbers selected by player as string
	void SetNumbersFromString(const std::string& str, std::array<int, 3>& nums);	//tokenize and set numbers from string as int
	bool IsInvalidData(const std::array<int, 3>& clientNums);	//validate is complete numbers data
	void SendResult(const Protocol& protocol);	//send comparation result
	void AddTryCount();		//add current try count
	void ResetTryCount();	//set try count to 0
	void SendTryCount();	//send try count to client
	void SendGameReport();	//send game report to client
};

