/*
 * UDPSocket.h
 *
 *  Created on: Apr 3, 2017
 *      Author: user
 */

#ifndef SRC_UDPSOCKET_H_
#define SRC_UDPSOCKET_H_
#include <strings.h>
#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include "Socket.h"

using namespace std;

namespace Lab {

class UDPSocket : public Socket{



public:
	UDPSocket(int port);
	virtual ~UDPSocket();
	void print();


 /* reads an incoming message from the UDP
	socket. the message is copied into the given buffer up to the specified length.
	int sendTo(string msg, string ip, int port) - sends the given message as a UDP
	message to the given address specified by IP and port.
*/

	 //int recv(char* buffer, int length);

 /* reply to an incoming message, this method will send the
	given message as a UDP message to the peer from which the last message was
	received.
*/
	//int reply(string msg);

	string fromAddr();

	//void closeSocket();

	//int sendTo(const string & msg, const string & ip,int port);


	 /* namespace Lab */
};

}

#endif /* SRC_UDPSOCKET_H_ */
