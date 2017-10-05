/*
 * MsgHandler.h
 *
 *  Created on: Jun 13, 2017
 *      Author: user
 */

#ifndef SRC_MSGHANDLER_H_
#define SRC_MSGHANDLER_H_
#include <stdlib.h>
#include <string>
using namespace std;
namespace Lab {

class MsgHandler {
public:
	MsgHandler();
	virtual ~MsgHandler();
	virtual void onMessageReceived(std::string message);
	virtual void onOpenSession(std::string ip, int port);
	virtual void onClosedSession();
};

} /* namespace Lab */

#endif /* SRC_MSGHANDLER_H_ */
