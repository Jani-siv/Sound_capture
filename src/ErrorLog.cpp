/*
 * ErrorLog.cpp
 *
 *  Created on: Dec 8, 2021
 *      Author: Gyy
 */

#include "ErrorLog.h"

ErrorLog::ErrorLog() {
	// TODO Auto-generated constructor stub
std::ofstream fd("/var/log/RecorderError.log", std::ofstream::out);
if (fd.is_open())
{
	fd << '\n';
}
fd.close();
}

ErrorLog::~ErrorLog() {
	// TODO Auto-generated destructor stub
}

void ErrorLog::newError(std::string errmsg)
{
	std::ofstream fd("/var/log/RecorderError.log", std::ofstream::out | std::ios::app);
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);
	std::ostringstream oss;
	oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
	std::string str;
	str = oss.str();
	std::string message = str + " " + errmsg + '\n';
	fd << message;
	fd.close();

}
