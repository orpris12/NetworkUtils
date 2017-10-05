/*
 * UDPSocket.cpp

 *
 *  Created on: Apr 3, 2017
 *      Author: user
 */

#include "UDPSocket.h"
#include "Guard.h"



using namespace std;

namespace Lab {


UDPSocket::UDPSocket(int port = 9999) : Socket(SOCK_DGRAM){

	int returnVal = 0;

//	returnVal = ::bind(fd,(struct sockaddr*)&s_in,sizeof(s_in));
//	if(returnVal<0){
//		cout<<"Error binding socket"<<endl;
//		closeSocket();
//	}
	bindSocket(port);

}

UDPSocket::~UDPSocket() {
	close();
}

//int UDPSocket::reply(string msg){
//	string ip = fromAddr();
//	return sendTo(msg, ip,ntohs(from.sin_port));
//}


//void UDPSocket::print(){
//	cout<<"this is a UDP socket print" << endl;
//}

//int UDPSocket::recv(char* buffer, int length){
//	int fromSize = sizeof(from);
//	int read = recvfrom(fd,buffer,length,0,(struct sockaddr*)&from,(socklen_t *)&fromSize);
//	return read;
//}

//string UDPSocket::fromAddr(){
//	string ip = inet_ntoa(from.sin_addr);
//	return ip;
//}

//int UDPSocket::sendTo(const string & msg, const string & ip,int port){
//	struct sockaddr_in outToClient;
//	bzero((char*)&outToClient,sizeof(outToClient));
//	outToClient.sin_family = (short)AF_INET;
//	outToClient.sin_addr.s_addr = inet_addr(ip.data());
//	outToClient.sin_port = htons(port);
//	int n = sendto(fd,msg.data(),msg.length(),0,(struct sockaddr*)&outToClient,sizeof(outToClient));
//	return n;
//}

//void UDPSocket::closeSocket(){
//	shutdown(fd,SHUT_RDWR);
//	::close(fd);
//	cout << "Socket is closed" << endl;
//}
}
