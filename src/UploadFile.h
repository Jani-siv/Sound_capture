/*
 * UploadFile.h
 *
 *  Created on: Nov 5, 2021
 *      Author: Gyy
 */

#ifndef UPLOADFILE_H_
#define UPLOADFILE_H_
#include <string>
#include <iostream>
#include <thread>
#include <inttypes.h>
#include "Commands.h"
#include "ReadOneFile.h"
class UploadFile {
public:
	UploadFile();
	~UploadFile();
	void initCurl();
	void sendFile(std::string filename, bool send);
private:
	uint8_t SOUND = 0x65;
	Commands com;
	ReadOneFile *rf;

};

#endif /* UPLOADFILE_H_ */
