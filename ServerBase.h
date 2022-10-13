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

	void ServiceSwitch(ClientSocket*& socket);	//received protocol switch
	void Registration();			//receive account data and register to db
	void ReadyForRegistration();	//receive protocol and validate is registration protocol
	void SendRegistrationResult();	//register account if receive registration protocol
	bool LogIn();					//receive account data and log in if is valid account
	void ReadyForLogIn();			//receive protocol and validate is log in protocol
	bool SendLogInResult();			//log in if receive log in protocol
	bool ReadyToPlayGame();			//receive protocol and validate is game execution
	void SendDisconnectionPacket();	//send disconnection request response protocol to client
	void Connect();					//accept connection with client and print log
	int retval;						
	void Disconnect();				//disconnection logger and clear client socket
	void ShutdownServer();			//release pointers before shutdown server
};