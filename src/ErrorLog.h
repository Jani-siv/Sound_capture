/*
 * ErrorLog.h
 *
 *  Created on: Dec 8, 2021
 *      Author: Gyy
 */

#ifndef ERRORLOG_H_
#define ERRORLOG_H_
#include <ctime>
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <iomanip>
class ErrorLog {
public:
	ErrorLog();
	virtual ~ErrorLog();
	void newError(std::string errmsg);
};

#endif /* ERRORLOG_H_ */
