/*
 * UploadFile.cpp
 *
 *  Created on: Nov 5, 2021
 *      Author: Gyy
 */

#include "UploadFile.h"
#define USERPASS user:password
#define ADDRESS https://address.com
#define OUTPUTFILE answer.txt
UploadFile::UploadFile() {
	// TODO Auto-generated constructor stub
	ReadOneFile rfl(this->SOUND);
	this->rf = &rfl;
}

UploadFile::~UploadFile() {
	// TODO Auto-generated destructor stub
}

void UploadFile::sendFile(std::string filename, bool send)
{
	if (this->rf->checkFilesignal(filename))
	{
		if (send == true)
		{
	std::string komento = "curl -s -X PUT -F file=@" + filename + " -u " + USERPASS + " " + ADDRESS + " > " OUTPUTFILE;
	system(komento.c_str());
	this->com.pollFile();
		}
	}
if (send == true)
{
	std::string command = "rm " + filename;
	system(command.c_str());
}
}

void UploadFile::initCurl()
{

}
