/*
 * File.h
 *
 *  Created on: Jun 1, 2017
 *      Author: user
 */

#ifndef SRC_FILE_H_
#define SRC_FILE_H_

#include <FileInterface.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


namespace Lab {

class File: public FileInterface {
protected:
	//ofstream* out;
	//ifstream* in;
public:
	File(string path);
	virtual ~File();
	virtual int read(char* buffer,int length);
	//writes the address of the integer
	virtual int read(int* integer);
	virtual int write(const char* msg, int length);
	//reads the address of the integer
	virtual int write(int integer);
	virtual int getDescriptor();
	virtual void close();


};

} /* namespace Lab */

#endif /* SRC_FILE_H_ */
