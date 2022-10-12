#include <iostream>
#include <winsock2.h>
#include"ServerBase.h"
//#ifndef SERVERBASE_H
//#define SERVERBASE_H
//#endif

int main(int argc, char* argv[]) {	
	ServerBase* server = new ServerBase();
	server->Run();
}