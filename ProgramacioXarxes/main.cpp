#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>
#include <Windows.h>
#include "GenericSocket.h"
#include "SocketTools.h"

int main() {
	SocketTools::OpenLibrary();

	GenericSocket socket1(SOCK_STREAM);

	sockaddr_in sa_in;
	sa_in.sin_addr.S_un.S_un_b.s_b1 = 127;
	sa_in.sin_addr.S_un.S_un_b.s_b2 = 0;
	sa_in.sin_addr.S_un.S_un_b.s_b3 = 0;
	sa_in.sin_addr.S_un.S_un_b.s_b4 = 1;

	std::cout << sa_in.sin_addr.S_un.S_addr<<std::endl;




	//SocketTools::CloseLibrary();

	system("pause");
}

