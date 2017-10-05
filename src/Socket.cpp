/*
 * Socket.cpp
 *
 *  Created on: May 22, 2017
 *      Author: user
 */

#include <Socket.h>

namespace Lab {

Socket::Socket(){

}
Socket::Socket(int type) {
	fd = socket(AF_INET,type,0);
	if(fd < 0 )
		cout << "Error establishing socket" << endl;
	int optlen;
	char *optval2;
	int optval = 1;
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
	setsockopt(fd, SOL_SOCKET, TCP_NODELAY, &optval, sizeof(optval));
	bzero((char*)&s_in, sizeof(s_in));
	bzero((char*)&from,sizeof(from));
}

int Socket::connect(string ip, int port) {
	int retVal = 0;
	retVal = inet_aton(ip.c_str(),&s_in.sin_addr);
	if(retVal == 0)
		perror("Invalid IP Adress given to client: ");
	s_in.sin_family = (short) AF_INET;
	s_in.sin_port = htons(port);
	retVal = ::connect(fd,(sockaddr*)&s_in,sizeof(s_in));
	if(retVal<0){
		perror("Client connecting to server socket");
		close();
	}

	return retVal;
}

int Socket::getLocalPort(){
	struct sockaddr_in temp;
	unsigned int size = sizeof(temp);
	bzero(&temp,sizeof(temp));
	getsockname(fd,(struct sockaddr *)&temp,&size);
	return ntohs(temp.sin_port);
}

int Socket::read(char* buffer, int length) {
	int read =	::read(fd,buffer,length);
	return read;
}

int Socket::read(int* integer){
	int read = ::read(fd,(char*)integer,4);
	*integer = ntohl(*integer);
	return read;
}

int Socket::write(const char* msg, int length) {
	int written = ::write(fd, msg, length);

	return written;
}

int Socket::write(int integer) {
	integer = htonl(integer);
	int written = ::write(fd, (char*)&integer,4);
	return written;
}
Socket::~Socket() {
	// TODO Auto-generated destructor stub
}

int Socket::bindSocket(int port) {
	int returnVal = 0;

	s_in.sin_addr.s_addr = htonl(0);
	s_in.sin_family=(short)AF_INET;
	s_in.sin_port= htons(port);

	returnVal = ::bind(fd,(struct sockaddr*)&s_in,sizeof(s_in));
	return returnVal;
}

void Socket::close() {
	::close(fd);
}

int Socket::getDescriptor() {
	return fd;
}

std::string Socket::getLocalIP() {
	struct sockaddr_in temp;
	char ipstr[16];
	unsigned int size = sizeof(temp);
	bzero(&temp,sizeof(temp));
	getsockname(fd,(struct sockaddr *)&temp,&size);
	 inet_ntop(AF_INET,(char*)&(temp.sin_addr.s_addr) , ipstr, sizeof ipstr);
	 string s(ipstr);
	return s;
}

int Socket::getRemotePort() {
	return s_in.sin_port;
}
} /* namespace Lab */

