/*
 * FileInterface.h
 *
 *  Created on: May 22, 2017
 *      Author: user
 */

#ifndef SRC_FILEINTERFACE_H_
#define SRC_FILEINTERFACE_H_
#include <iostream>
#include <string.h>
using namespace std;
namespace Lab {

class FileInterface {
protected:
	int fd;

public:
	FileInterface();
	virtual ~FileInterface();
	virtual int read(char* buffer,int length)=0;
	virtual int read(int* integer)=0;
	virtual int write(const char* msg, int length)=0;
	virtual int write(int integer) =0;
	virtual int getDescriptor()=0;
	virtual void close()=0;
};

} /* namespace Lab */

#endif /* SRC_FILEINTERFACE_H_ */

