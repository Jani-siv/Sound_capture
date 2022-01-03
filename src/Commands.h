/*
 * Commands.h
 *
 *  Created on: Dec 2, 2021
 *      Author: Gyy
 */

#ifndef COMMANDS_H_
#define COMMANDS_H_
#include <iostream>
#include <fstream>
#include <stdbool.h>
#include <string>
#include <unistd.h>
#include "ErrorLog.h"
class Commands {
public:
	Commands();
	virtual ~Commands();
	void pollFile();
private:
	int readFile(std::string filename);
	ErrorLog * log;


};

#endif /* COMMANDS_H_ */
