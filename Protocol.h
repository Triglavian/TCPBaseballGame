#pragma once

enum class Protocol
{
	DISCONNECTION = 0,	//disconnection protocol, recivec if opps socket is closed

	REGISTRAION = 10,	//registration protocol, client to server
	REGISTRATIONREADY,	//registration ready protocol, server to client
	REGISTRATIONSUCCESS,//registration result protocol, server to client
	REGISTRAIONFAIL,	//registration result protocol, server to client

	LOGIN,				//login protocol, client to server
	LOGINREADY,			//login ready protocol, server to client
	LOGINSUCCESS,		//login result protocol, server to client
	LOGINFAIL,			//login result protocol, server to client

	EXIT,				//disconnect protocol, client to server

	EXECUTEGAME,		//game execute protocol, client to server
	EXECUTEGAMERDY,		//game execute ready protocol, server to client

	PLAYGAME,			//play game protocol, client to server
	PLAYGAMEREADY,		//play game ready protocol, server to client

	INPUTNUM,			//get number input protocol, cliesnt to server
	RETURNNOTOUTRESULT,	//result returning protocol, server to client
	RETURNOUTRESULT,	//result returning protocol, server to client

	SENDTRYCOUNT,		//send try count protocol, server to client
	RECVTRYCOUNT,		//receive try count protocol, client to server

	SENDREPORT,			//send game report protocol, server to client
	RECVREPORT,			//receive game report protocol, client to server

	QUITGAME,			//quit game protocol, client to server
	QUITGAMEREADY,		//quit game ready protocol, server to client

	MAX					//do not use

#define DISCON	Protocol::DISCONNECTION
#define REG		Protocol::REGISTRAION
#define REGRDY	Protocol::REGISTRATIONREADY
#define REGSUC	Protocol::REGISTRATIONSUCCESS
#define REGFAIL	Protocol::REGISTRAIONFAIL
#define LIN		Protocol::LOGIN
#define LINRDY	Protocol::LOGINREADY
#define LINSUC	Protocol::LOGINSUCCESS
#define LINFAIL	Protocol::LOGINFAIL
#define EXIT	Protocol::EXIT

#define EXEGAME	Protocol::EXECUTEGAME
#define GAMERDY	Protocol::EXECUTEGAMERDY
#define PLAY	Protocol::PLAYGAME
#define PLAYRDY	Protocol::PLAYGAMEREADY
#define INNUM	Protocol::INPUTNUM
#define RETNOUT	Protocol::RETURNNOTOUTRESULT
#define RETOUT	Protocol::RETURNOUTRESULT	
#define SENDCNT	Protocol::SENDTRYCOUNT
#define RECVCNT	Protocol::RECVTRYCOUNT
#define SENDREP	Protocol::SENDREPORT
#define RECVREP Protocol::RECVREPORT
#define QUIT	Protocol::QUITGAME
#define QUITRDY	Protocol::QUITGAMEREADY
};