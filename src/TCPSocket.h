/*
 * TCPSocket.h
 *
 *  Created on: May 5, 2017
 *      Author: user
 */

#ifndef SRC_TCPSOCKET_H_
#define SRC_TCPSOCKET_H_


#include <string>
#include "Socket.h"

using namespace std;

namespace Lab {

class TCPSocket: public Socket{
protected:
	int backlog;

public:
	TCPSocket(int port = 9999);
	TCPSocket(string ip,int port);
	TCPSocket(int connected_sock,struct sockaddr_in* serverAddr,struct sockaddr_in* peerAddr);
	TCPSocket* listenAndAccept();

//	int recv(char* buffer,int length);
//	int send(const char* toSend,int length);
//	void closeTCPSocket();
	string fromAddr();
//	bool isActive();

	virtual ~TCPSocket();
};

} /* namespace Lab */

#endif /* SRC_TCPSOCKET_H_ */
