#include "SocketTools.h"



SocketTools::SocketTools()
{
}


SocketTools::~SocketTools()
{
}

void SocketTools::OpenLibrary()
{
	WSADATA jola;
	int temp = WSAStartup(MAKEWORD(2, 2), &jola);
	if (temp != 0) 
		ShowError("Error al abrir libreria: ");
	else ShowError("Libreria abierta correctamente: ");
	//WSACleanup();
}

void SocketTools::CloseLibrary()
{
	int temp = WSACleanup();
	if (temp != 0)
		ShowError("Error al cerrar libreria: ");
}

void SocketTools::ShowError(std::string error) {
	
	std::cout << error << WSAGetLastError() << std::endl;
}