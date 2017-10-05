/*
 * TCPSocket.cpp
 *
 *  Created on: May 5, 2017
 *      Author: user
 */

#include <TCPSocket.h>

namespace Lab {

//TCPSocket::TCPSocket(int port) {
//
//	int retVal = 0;
//	this->port = port;
//	backlog = 1;
//	this->socketId = socket(AF_INET,SOCK_STREAM,0);
//	if(socketId < 0)
//		perror("Error opening server socket: ");
//
//	int optlen;
//
//		char *optval2;
//
//		int optval = 1;
//
//		setsockopt(socketId, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
//
//	bzero((char*)&s_in,sizeof(s_in));
//	bzero((char*)&from,sizeof(from));
//
//	s_in.sin_addr.s_addr = INADDR_ANY;
//	s_in.sin_family = (short) AF_INET;
//	s_in.sin_port = htons(port);
//
//	retVal = bind(socketId,(struct sockaddr*)&s_in,sizeof(s_in));
//	if(retVal < 0)
//		perror("Binding server socket: ");
//
//	active = true;
//
//}
TCPSocket::TCPSocket(int port): Socket(SOCK_STREAM){
	backlog = 1;
	bindSocket(port);
}

TCPSocket::TCPSocket(string ip,int port): Socket(SOCK_STREAM){
//	int retVal = 0;
//	this->port = port;
//	this->backlog = 1;
//
//	this->socketId = socket(AF_INET,SOCK_STREAM,0);
//	if(socketId < 0)
//		perror("Opening client socket: ");
//	int optlen;
//	char *optval2;
//	int optval = 1;
//	setsockopt(socketId, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
//
//	bzero((char*)&s_in,sizeof(s_in));
//	bzero((char*)&from,sizeof(from));
//
//	retVal = inet_aton(peerIp.c_str(),&s_in.sin_addr);
//	if(retVal == 0)
//		perror("Invalid IP Adress given to client: ");
//	s_in.sin_family = (short) AF_INET;
//	s_in.sin_port = htons(port);
//
//	retVal = 0;
//	retVal = connect(socketId,(sockaddr*)&s_in,sizeof(s_in));
//	if(retVal<0){
//		perror("Client connecting to server socket");
//		closeTCPSocket();
//	}
	backlog = 1;
	connect(ip, port);
	sockaddr_in local;
	socklen_t len= sizeof(local);
	getsockname(fd,(sockaddr*)&local,&len);

}

TCPSocket::TCPSocket(int connected_sock,struct sockaddr_in* serverAddr,struct sockaddr_in* peerAddr):Socket(){
	this->fd = connected_sock;
	this->s_in = *serverAddr;
	this->from = *peerAddr;
	this->backlog = 1;
}

TCPSocket* TCPSocket::listenAndAccept(){
	int retVal = 0;
	int newSocket = 0;
	int i=0;
	retVal = listen(fd,this->backlog);
	if(retVal < 0){
		perror("Listening in server socket: ");
		close();
	}
	unsigned int fromSize = sizeof(from);
	newSocket = accept(fd,(sockaddr*)&from,&fromSize);
	if(newSocket<0){
		perror("Accepting connection in server socket: ");
		close();
	}
	TCPSocket *newSock = new TCPSocket(newSocket,&this->s_in,&this->from);
	return newSock;

}


//int TCPSocket::recv(char* buffer,int length){
//	return read(socketId,buffer,length);
//}
//
//int TCPSocket::send(const char* toSend,int length){
//	return write(socketId,toSend,length);
//}
//
std::string TCPSocket::fromAddr(){
	return inet_ntoa(from.sin_addr);
}
//
//void TCPSocket::closeTCPSocket(){
//	cout << "Socket #"<<socketId<<" is closing" << endl;
//	shutdown(socketId,SHUT_RDWR);
//	close(socketId);
//	active = false;
//
//}



TCPSocket::~TCPSocket() {
	close();

}



} /* namespace Lab */


