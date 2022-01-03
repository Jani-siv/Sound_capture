/*
 * ReadOneFile.cpp
 *
 *  Created on: Dec 3, 2021
 *      Author: Gyy
 */

#include "ReadOneFile.h"

ReadOneFile::ReadOneFile(uint8_t sound) {
	// TODO Auto-generated constructor stub
this->MAXsound = sound;
}

ReadOneFile::~ReadOneFile() {
	// TODO Auto-generated destructor stub
}
uint8_t ReadOneFile::calculateWeight(uint16_t data)
{

	if (data % 0x2 > 0)
	{
		data += 0x01;
	}
uint8_t low = data & 0xFF;
uint8_t high = data >> 8;
uint16_t answer = 0x00;
answer = (low + high) /2;
return answer & (0xFF);
}

bool ReadOneFile::checkFilesignal(std::string filename)
{
	//this->modifyFile(filename);
bool answer = false;
uint16_t pair = 0x00;

char data[2];
std::ifstream fd;
fd.open(filename, std::ios::in);
if (fd.is_open())
{
fd.seekg(0,fd.end);
int fsize = fd.tellg();
fd.seekg(0,fd.beg);
//skip most of the header
for (int i = 224; i < fsize; i++)
{
if (i < fsize)
{
	uint8_t midpoint = 0x00;
    fd.seekg(i,std::ios::beg);
    fd.read(data,sizeof(data)/sizeof(char));
    pair = data[0];
    pair = pair << 8;
    pair += data[1];
    midpoint = this->calculateWeight(pair);
    if (midpoint > 0x7F)
    {
    	return true;
    }
    i++;
}
}}
return answer;
}

void ReadOneFile::modifyFile(std::string filename)
{
	std::string commandStr = "ffmpeg -i " + filename + " "  + "new" + filename +" > /dev/null 2>&1 ";
	std::string modifyNameBack = "rm "+ filename +" && mv new"+filename +" " + filename;
	system(commandStr.c_str());
	system(modifyNameBack.c_str());
}
