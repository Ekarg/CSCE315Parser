/* 
    File: parserMain.cpp

    Authors: Grace Coffman, Sidian Wu, Wesley Tang
            Department of Computer Science
            Texas A&M University
			
    This file contains the main function for testing database parser.

*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include "parser.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	while (true) {
		cout<<"Please input command\n";
		string input;
		//cin>>input;
		getline(cin, input);
		if(input == "Hello_World") {
			break;
		}
		Parser p = Parser();
		bool valid = p.validate(input);
		if(valid)
			cout<<"Command is valid.\n";
		else
			cout<<"Error: Command is NOT valid\n";
	}
	return 0;
}

