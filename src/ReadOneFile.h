/*
 * ReadOneFile.h
 *
 *  Created on: Dec 3, 2021
 *      Author: Gyy
 */

#ifndef SRC_READONEFILE_H_
#define SRC_READONEFILE_H_
#include <string>
#include <fstream>
#include <iostream>
#include <stdbool.h>
#include <stdint.h>
class ReadOneFile {
public:
	ReadOneFile(uint8_t sound);
	~ReadOneFile();
	bool checkFilesignal(std::string filename);
private:
	std::string fname;
	uint8_t MAXsound = 0x8F;
	uint8_t calculateWeight(uint16_t data);
	void modifyFile(std::string filename);

};

#endif /* SRC_READONEFILE_H_ */
