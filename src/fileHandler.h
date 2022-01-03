/*
 * fileHandler.h
 *
 *  Created on: Nov 3, 2021
 *      Author: Gyy
 */

#ifndef FILEHANDLER_H_
#define FILEHANDLER_H_
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sound/asound.h>
int openFile(std::string dev)
{
	char* device = new char [dev.length()+1];
	std::strcpy(device,dev.c_str());


	return 0;
}

























#endif /* FILEHANDLER_H_ */
