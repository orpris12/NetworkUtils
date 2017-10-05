/*
 * MultipleSocketListener.cpp
 *
 *  Created on: May 15, 2017
 *      Author: user
 */

#include "MultipleSocketListener.h"

namespace Lab {

MultipleSocketListener::MultipleSocketListener() {
	socketNum = 0;
	this->dummy = new UDPSocket(0);
	this->dummyPort = dummy->getLocalPort();
}

MultipleSocketListener::~MultipleSocketListener() {
	// TODO Auto-generated destructor stub
}

void MultipleSocketListener::addSocket(TCPSocket* socket){

	if(socket != NULL)
	{
		sockets.push_back(socket);
		socketNum++;
	}

}

void MultipleSocketListener::addSockets(vector<TCPSocket*> socketVec){

	sockets.clear();
	sockets = socketVec;
	socketNum =(int) socketVec.size();
}

int MultipleSocketListener::getMaxFd(vector<TCPSocket*> vector) {
	int max = 0;
	for(int i=0;i<(int)vector.size();i++){
		if(max < vector[i]->getDescriptor())
			max = vector[i]->getDescriptor();
	}
	return max;
}

TCPSocket* MultipleSocketListener::listenToSocket(){
	//define the fd_set and initialize it
	fd_set fds;
	FD_ZERO(&fds);

	//add a dummy socket to the set
	FD_SET(dummy->getDescriptor(),&fds);

	for(int i = 0;i<(int)sockets.size();i++){
		if(sockets[i] != NULL){
			FD_SET(sockets[i]->getDescriptor(),&fds);
		}
	}
	//find the max fd
	int retVal,maxFd;
	if(getMaxFd(sockets) > dummy->getDescriptor())
		maxFd = getMaxFd(sockets);
	else maxFd = dummy -> getDescriptor();

	//perform the select function to get the right socket
	retVal = select((maxFd + 1),&fds,NULL,NULL,NULL);
	if(retVal){
		for(int i=0;i<(int)sockets.size();i++){
			if(FD_ISSET(sockets[i]->getDescriptor(),&fds))
				return sockets[i];
		}
		if(FD_ISSET(dummy->getDescriptor(),&fds)){
			int num;
			dummy->read(&num);
		}

	}
	return NULL;

}

void MultipleSocketListener::interrupt() {
	if(dummy != NULL){
		UDPSocket* sock = new UDPSocket(4547);
		sock->connect("127.0.0.1",dummyPort);
		sock->write(1);
	}
}


void MultipleSocketListener::removeSocket(TCPSocket* socket) {

	for(unsigned int i=0;i<sockets.size();i++){
		if(sockets[i]->getLocalPort() == socket->getLocalPort()){
			sockets.erase(sockets.begin()+i);
			break;
		}
	}
}

} /* namespace Lab */

