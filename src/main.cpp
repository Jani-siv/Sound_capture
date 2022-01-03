//============================================================================
// Name        : main.cpp
// Author      : Jani Sivonen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++
// Depencies   : libasound2-dev libcurl4-openssl-dev telnet for controlling lights
//TODO  while ((c = getopt (argc, argv, "8a:f:mr:t:vc:")) != EOF)
//============================================================================

#include "menu.h"
#include "SoundRecorder.h"
#include "Commands.h"
#include <thread>

#include <iostream>
int testNum(char* str)
{
	unsigned len = strlen(str);
	for (unsigned i = 0; i < len; i++)
	{
		if (std::isalpha(str[i]))
		{
			return -1;
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc < 4 && argc > 1)
	{
		if (argv[1][0] == '-' && argv[1][1] == 'h')
		{
			menu();
			return 0;
		}
		if (argv[1][0] == '-' && argv[1][1] == 's')
		{

		int samples = std::stoi(argv[2]);
		for (int i = 0; i < samples; i++)
		{
			std::cout<<"***************************TAP***********************"<<std::endl;
			std::cout<<"*****************************************************"<<std::endl;
			std::cout<<"***************************TAP***********************"<<std::endl;
			SoundRecorder sound(false,false);
			std::cout<<"***************************STOP***********************"<<std::endl;
			sleep(1);
		}
		return 1;
		}
		if (argv[1][0] == '-' && argv[1][1] == 'a')
		{
			while(1)
			{
				std::cout<<"always"<<std::endl;
			SoundRecorder sound(true,false);
			}
		}
	}

SoundRecorder sound(true,false);

std::cout<<"exit normal"<<std::endl;
  return 0;
}
