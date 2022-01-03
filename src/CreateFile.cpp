/*
 * CreateFile.cpp
 *
 *  Created on: Nov 5, 2021
 *      Author: Gyy
 */

#include "CreateFile.h"

CreateFile::CreateFile() {
	// TODO Auto-generated constructor stub

}

CreateFile::~CreateFile() {
	// TODO Auto-generated destructor stub
}

std::string CreateFile::createWavFile(char* memaddr, int memSize, int channels)
{
	//get current time for filename
	std::time_t current = std::time(NULL);
	std::stringstream stream;
	stream << current;
	std::string filename = stream.str() + ".wav";

	this->createHeader(memSize);
	if (channels == 2)
	{
		this->header.ChunkSize = __builtin_bswap32 (0x34B10200);
		this->header.NumOfChan = __builtin_bswap16 (0x0200);
		this->header.bytesPerSec = __builtin_bswap32(0x007D0000);
	}
	std::ofstream out(filename.c_str());
	out.write(reinterpret_cast<char*>(&this->header), sizeof(this->header));
	//std::cout<<"start writing to file"<<std::endl;
	for (int i = 0; i < (memSize-768); i++)
			{
				out.write(&memaddr[i],sizeof(char));
			}
		out.close();

return filename;
}

void CreateFile::createHeader(int fileSize)
{
this->header.RIFF[0] = 'R';
this->header.RIFF[1] = 'I';
this->header.RIFF[2] = 'F';
this->header.RIFF[3] = 'F';
this->header.ChunkSize = __builtin_bswap32(0x247D0000);
this->header.WAVE[0] = 'W';
this->header.WAVE[1] = 'A';
this->header.WAVE[2] = 'V';
this->header.WAVE[3] = 'E';
this->header.fmt[0] = 'f';
this->header.fmt[1] = 'm';
this->header.fmt[2] = 't';
this->header.fmt[3] = 0x20;
this->header.Subchunk1Size = __builtin_bswap32 (0x10000000);
this->header.AudioFormat =__builtin_bswap16 (0x0100);
this->header.NumOfChan = __builtin_bswap16 (0x0100);
this->header.SamplesPerSec = __builtin_bswap32 (0x803E0000);
this->header.bytesPerSec = 16000*2; //hox
this->header.blockAlign = __builtin_bswap16 (0x0200);
this->header.bitsPerSample = __builtin_bswap16 (0x1000);
this->header.Subchunk2ID[0] = 'd';
this->header.Subchunk2ID[1] = 'a';
this->header.Subchunk2ID[2] = 't';
this->header.Subchunk2ID[3] = 'a';

this->header.Subchunk2Size = __builtin_bswap32(0x007D0000);

}


