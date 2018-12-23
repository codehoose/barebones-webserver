#include "MultiClientChat.h"
#include <string>

void MultiClientChat::onClientConnected(int clientSocket)
{
	// Send a welcome message to the connected client
	std::string welcomeMsg = "Welcome to the Awesome Chat Server!\r\n";
	sendToClient(clientSocket, welcomeMsg.c_str(), welcomeMsg.size() + 1);
}

void MultiClientChat::onClientDisconnected(int clientSocket)
{

}

void MultiClientChat::onMessageReceived(int clientSocket, const char* msg, int length)
{
	broadcastToClients(clientSocket, msg, length);
}