#pragma once
#include <WinSock2.h>
#include <Windows.h>
#include <WS2tcpip.h>
#include <String>

class SocketAdress
{

private:
	sockaddr_in address;
public:
	SocketAdress();
	SocketAdress(SocketAdress &toCopy);
	SocketAdress(int b1, int b2, int b3, int b4, int port);
	int SetAdress(const std::string & inString);
	~SocketAdress();
};

