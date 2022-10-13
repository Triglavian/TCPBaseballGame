#pragma once
#include <iostream>
#include <WinSock2.h>
#include <ws2tcpip.h>

class ServerLogManager
{
public:
	ServerLogManager();
	~ServerLogManager();
	void SetClientInetInfoToMsg(sockaddr_in clientAddr);	//set socket dest address to string
	//void ShowClientInfo();	//print connected client's data
private:
	std::string logMsg;
	std::string buf;
};

