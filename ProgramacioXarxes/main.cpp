#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>
#include <Windows.h>
#include "GenericSocket.h"
#include "SocketTools.h"

int main() {
	SocketTools::OpenLibrary();

	GenericSocket socket1(SOCK_STREAM);

	SocketTools::CloseLibrary();

	system("pause");
}

