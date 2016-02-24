#include "UDPSocket.h"
#include "SocketTools.h"
#include <iostream>
#include <string>

void ClientLoop(std::string direccion)
{

	while (true) {
		UDPSocket socket;
		SocketAddress address;

		address.SetAddress(direccion);
		//Cliente
		
		std::string input;
		std::getline(std::cin,input);

		socket.Enviar(input.c_str(), sizeof(input), address);


		if (input == "exit") {
			break;
		}
	}

	

		
	

}

void ServerLoop(std::string direccion) {
	while (true) {
		UDPSocket socket;
		SocketAddress address;
		address.SetAddress(direccion);
		socket.Bind(address);
		char data[1300];
		socket.Recibir(data, sizeof(data), address);

		std::cout << data;

		if (std::strcmp(data, "exit") == 0) {

			break;
		}
	}

}

int main(int argc, char *argv[])
{
	
	SocketTools::CargarLibreria();
	std::string funcion = argv[1];
	std::string direccion = argv[2];

	if (funcion == "cliente") {
		ClientLoop(direccion);
	}

	else if (funcion == "servidor") {
		ServerLoop(direccion);
	}
	
	SocketTools::DescargarLibreria();
	//GenericSocket::Bind();
	system("pause");
}