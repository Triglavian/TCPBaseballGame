#pragma once
#include <iostream>
#include <WinSock2.h>
#include <ws2tcpip.h>

class ServerLogManager
{
public:
	ServerLogManager();
	~ServerLogManager();
	void SetClientInetInfoToMsg(sockaddr_in clientAddr);
	void ShowClientInfo();
private:
	std::string logMsg;
	//std::ostream oStream;
	//char buf[500];
	std::string buf;
};

