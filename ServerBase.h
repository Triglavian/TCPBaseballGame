#include "ServerSocket.h"
#include "ClientSocket.h"
#include <WS2tcpip.h>
#include "AccountManager.h"
#include "Protocol.h"
#include "BaseballGameManager.h"

class ServerBase
{
public:
	ServerBase();
	~ServerBase();
	void Run();				//run server
private:
	WSADATA wsaData;		//window socket api
	ServerSocket* lSocket;	//server listen socket
	ClientSocket* cSocket;	//client connection socket
	AccountManager* accountManager;
	BaseballGameManager* gameManager;
	bool Initialization();	//server initialization
	bool IsWSAStartFail();	//validate initialization
	int result;				//event result	
	char addr[INET_ADDRSTRLEN];
	bool loopFlag;

	void ServiceSwitch(ClientSocket*& socket);
	void Registration();
	void ReadyForRegistration();
	void SendRegistrationResult();
	bool LogIn();
	void ReadyForLogIn();
	bool SendLogInResult();
	bool ReadyToPlayGame();
	void SendDisconnectionPacket();
	void Connect();
	int retval;
	void Disconnect();
	void ShutdownServer();
};