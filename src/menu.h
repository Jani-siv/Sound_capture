/*
 * menu.h
 *
 *  Created on: Nov 5, 2021
 *      Author: Gyy
 */

#ifndef MENU_H_
#define MENU_H_
#include <iostream>
void menu()
{
	std::cout<<"How use program"<<std::endl;
	std::cout<<"Example to test run program \"./recorder"<<std::endl;
	std::cout<<"You need set all flags to run program"<<std::endl;
	std::cout<<"-a = run non-stop"<<std::endl;
	std::cout<<"-s 100 = record 100 samples"<<std::endl;
	std::cout<<"-h = this menu"<<std::endl;
	std::cout<<"all errors found from error.log file"<<std::endl;
}




#endif /* MENU_H_ */
