#pragma once
#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <string>

class SocketTools
{
public:
	
	static void OpenLibrary();
	static void CloseLibrary();
	static void ShowError(std::string error);

	
	SocketTools();
	~SocketTools();
};

