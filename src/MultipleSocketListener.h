/*
 * MultipleSocketListener.h
 *
 *  Created on: May 15, 2017
 *      Author: user
 */

#ifndef SRC_MULTIPLESOCKETLISTENER_H_
#define SRC_MULTIPLESOCKETLISTENER_H_

#include <vector>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "TCPSocket.h"
#include <algorithm>
#include "UDPSocket.h"
using namespace std;
namespace Lab {

class MultipleSocketListener {
private:
	vector<TCPSocket*> sockets;
	int socketNum;
	UDPSocket* dummy;
	int dummyPort;
	int getMaxFd(vector<TCPSocket*> vector);
public:
	MultipleSocketListener();
	virtual ~MultipleSocketListener();
		 //Add the given socket to the socket list to be listen on
		void addSocket(TCPSocket* socket);
		//Set the given sockets to the socket list to be listen on
		void addSockets(vector<TCPSocket*> socketVec);
		/* This method checks to see if any of the previous given sockets are ready for reading
		 * It returns one of the Sockets that are ready.
		 */
		TCPSocket* listenToSocket();
		void interrupt();
		void removeSocket(TCPSocket* socket);
};

} /* namespace Lab */

#endif /* SRC_MULTIPLESOCKETLISTENER_H_ */
