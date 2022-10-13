#pragma once
#include <WinSock2.h>
#include "PacketHandler.h"

class ClientSocket
{
public:
	ClientSocket();
	~ClientSocket();
	void AcceptConnection(const SOCKET lSocket);	//accept connection
	bool IsFailToAccept();		//validate accept() result
	sockaddr_in* GetSockAddr();	//get client ip address

	//send packet
	int SendBoolPacket(const Protocol& protocol);
	int SendBoolPacket(const Protocol& protocol, const bool& flag);
	int SendIntPacket();
	int SendAccPacket();
	int SendStrPacket();
	int SendResultPacket();
	int SendReportPacket(const GameReport& report);

	//receive packet
	int RecvBoolPacket();
	int RecvIntPacket();
	int RecvAccPacket();
	int RecvStrPacket();
	int RecvResultPacket();

	//set data
	void SetNum(const int& num);
	void SetFlag(const bool& flag);
	void SetProtocol(const Protocol& protocol);
	void SetResult(const Result& result);

	//get data
	int Getnum();
	bool GetFlag();
	Protocol GetProtocol();
	AccountForm& GetAccountData();
	std::string GetStr();
	Result GetResult();
	void ClearTempDatas();	//clear flag, num, acc
private:
	int retval;
	SOCKET* socket;				//client qsocket
	sockaddr_in* clientAddr;	//cliend address
	int addrLen;				//client address object size
	void SetAddrLen();			//set client address object size to val	
	PacketHandler packetHandler;
	Protocol protocol;
	AccountForm acc;
	Result result;
	int num;
	bool flag;
	std::string str;
};
