#include "ServerLogManager.h"

ServerLogManager::ServerLogManager()
{
	logMsg.clear();
}

ServerLogManager::~ServerLogManager()
{

}

void ServerLogManager::SetClientInetInfoToMsg(sockaddr_in clientAddr)
{
	logMsg.clear();
	//inet_ntop(AF_INET, &clientAddr.sin_addr, buf, sizeof(buf));
	inet_ntop(AF_INET, &clientAddr.sin_addr, const_cast<char*>(buf.c_str()), sizeof(buf));	//linker error
	sprintf_s((char*)logMsg.c_str(), sizeof(logMsg.c_str()), "Client IP : %s, Port Num = %d", buf.c_str(), clientAddr.sin_port);
}

void ServerLogManager::ShowClientInfo()
{
	//std::cout<<"Client IP : " << logMsg << ", Port Num = "
}
