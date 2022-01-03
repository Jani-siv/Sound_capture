/*
 * CreateFile.h
 *
 *  Created on: Nov 5, 2021
 *      Author: Gyy
 */

#ifndef CREATEFILE_H_
#define CREATEFILE_H_
#include "Riff.h"
#include <fstream>
#include <ctime>
#include <string>
#include <iostream>
#include <sstream>
class CreateFile {
public:
	CreateFile();
	~CreateFile();
	std::string createWavFile(char* memaddr, int memSize, int channels);

private:
	void createHeader(int fileSize);

	WAV_HEADER header;
};

#endif /* CREATEFILE_H_ */
