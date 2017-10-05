/*
 * Socket.h
 *
 *  Created on: May 22, 2017
 *      Author: user
 */

#ifndef SRC_SOCKET_H_
#define SRC_SOCKET_H_
#include "FileInterface.h"
#include <strings.h>
#include <string.h>
#include <iostream>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include "Socket.h"
namespace Lab {

class Socket : public FileInterface{
	protected:
	sockaddr_in s_in,from;
public:
	Socket();
	Socket(int type);
	virtual int read(char* buffer,int length);
	virtual int read(int* integer);
	virtual int write(const char* msg, int length);
	virtual int write(int integer);
	virtual int getDescriptor();
	int bindSocket(int port);
	int connect(string ip,int port);
	int getLocalPort();
	int getRemotePort();
	std::string getLocalIP();
	virtual ~Socket();
	virtual void close();

};

} /* namespace Lab */

#endif /* SRC_SOCKET_H_ */
