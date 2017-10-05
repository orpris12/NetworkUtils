/*
 * File.cpp
 *
 *  Created on: Jun 1, 2017
 *      Author: user
 */

#include <File.h>

namespace Lab {

File::File(string path) {

	//out = new ofstream(path.c_str(),ios::app);
	//in = new ifstream(path.c_str());
	//in->seekg(0,ios_base::beg);
	mode_t mode =  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	fd = open(path.c_str(),O_RDWR | O_APPEND | O_CREAT, mode);
	if(fd<0){
		perror("Opening file failed");
	}


}

File::~File() {
	// TODO Auto-generated destructor stub
}

int File::read(char* buffer, int length) {
	//in->getline(buffer,length);
	int read = ::read(fd,buffer,length);
	return read;
}

int File::read(int* integer) {
	//*in >> *integer;
	int read = ::read(fd,integer,sizeof(*integer));
	return read;
}

int File::write(const char* msg, int length) {
	//*out << msg;
	int write = ::write(fd,msg,length);
	return write;
}

int File::write(int integer) {
	//*out << integer;
	int write = ::write(fd,&integer,sizeof(integer));
	return write;
}

int File::getDescriptor() {
	return fd;
}

void File::close() {
	::close(fd);
}

} /* namespace Lab */

