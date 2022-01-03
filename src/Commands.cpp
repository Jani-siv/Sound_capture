/*
 * Commands.cpp
 *
 *  Created on: Dec 2, 2021
 *      Author: Gyy
 */

#include "Commands.h"

Commands::Commands() {
	// TODO Auto-generated constructor stub
	std::cout<<"polling file"<<std::endl;
ErrorLog logi;
	this->log = &logi;

}

Commands::~Commands() {
	// TODO Auto-generated destructor stub
}

void Commands::pollFile()
{
	int log = 0;
	int answer = this->readFile("answer.txt");
	if (answer == 0)		{ this->log->newError("Error in connection to neuralnetwork");}
	else if (answer == 1) 	{std::cout<<"lights on"<<std::endl;
							log = system("./on.sh");}
	else if (answer == 2) 	{std::cout<<"lights off"<<std::endl;
							log = system("./off.sh");}
if (log < 0)
{
	this->log->newError("Error to connect iot device");
}
}

int Commands::readFile(std::string filename)
{
	int answer=0;
	std::ifstream fd;
	fd.open(filename);
	fd.seekg(0,fd.end);
	int size = fd.tellg();
	fd.seekg(0,fd.beg);
	char buffer[size];
	for (int i = 0; i < size; i++)
	{
		fd.get(buffer[i]);
	}
	//std::cout<<buffer<<std::endl;
	if (buffer[0] == 0x5B)
	{
		if (buffer[2] == 0x6F)
		{
			return 1;
		}
		else if (buffer[2] == 0x74)
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}
return answer;
}

