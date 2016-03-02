#include "UDPSocket.h"
#include "SocketTools.h"
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mut;
std::vector<std::string> messageBuffer;

/*void ClientLoop(std::string direccion)
{

	while (true) {
		UDPSocket socket;
		SocketAddress address;

		address.SetAddress(direccion);
		//Cliente
		
		
		std::string input;
		std::getline(std::cin, input);

		socket.Enviar(input.c_str(), sizeof(input), address);


		if (input == "exit") {
			break;
		}
	}
}*/

/*void ServerLoop(std::string direccion) {
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

}*/

void gotoxy(int x, int y) {

	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}

void printList() {
	gotoxy(0, 0);

	mut.lock();

	for (auto itr = messageBuffer.begin(), end_itr = messageBuffer.end(); itr != end_itr; ++itr) {
		std::cout << *itr << std::endl;
	}
	mut.unlock();
	gotoxy(0, 20);

}

void sendy(UDPSocket socket, SocketAddress receiver) {
	
	while (true) {
		gotoxy(0, 20);
		std::string input;
		std::getline(std::cin, input);

		mut.lock();
		messageBuffer.push_back(input);
		if (messageBuffer.size() >= 20) {
			messageBuffer.erase(messageBuffer.begin());
		}
		mut.unlock();

		socket.Enviar(input.c_str(), 1300, receiver);
		system("cls");
		printList();

	}

}


void receive(UDPSocket socket){
	
	char data[1300];
	SocketAddress sender;
	while (true) {
		
		socket.Recibir(data, sizeof(data), sender);
		
		mut.lock();
		messageBuffer.push_back(data);

		if (messageBuffer.size() >= 20) {
			messageBuffer.erase(messageBuffer.begin());
		}
		mut.unlock();
		system("cls");
		printList();

		
	}

	

}

void ChatLoop(std::string direccion1, std::string direccion2) {
	
		//Socket recepción
		UDPSocket socketReceive;
		SocketAddress addressReceive;
		addressReceive.SetAddress(direccion1);
		socketReceive.Bind(addressReceive);
		
		//Socket envío
		UDPSocket socketSend;
		SocketAddress addressSend;
		addressSend.SetAddress(direccion2);

		//Creamos los threads necesarios para el envío y recepción
		std::thread receiver(receive,socketReceive);
		std::thread sender(sendy,socketSend,addressSend);

		receiver.join();
		sender.join();

}

int main(int argc, char *argv[])
{
	//Cargamos librería sockets
	SocketTools::CargarLibreria();

	//Recibimos los argumentos de consola que nos indican qué dirección y puerto escuchar y a qué dirección y puerto mandar
	std::string direccionRecepcion = argv[1];
	std::string direccionEnvio = argv[2];
	
	//Loop del chat
	ChatLoop(direccionRecepcion,direccionEnvio);

	//Liberamos la librería
	SocketTools::DescargarLibreria();

	std::cout << "Sesión finalizada.";
	system("pause");
}