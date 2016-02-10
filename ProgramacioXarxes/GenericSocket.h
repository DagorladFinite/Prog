#pragma once
#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>
#include <Windows.h>
#include "SocketTools.h"

class GenericSocket
{
private:
	SOCKET s;
public:
	
	GenericSocket();
	GenericSocket(int type);
	~GenericSocket();
};

