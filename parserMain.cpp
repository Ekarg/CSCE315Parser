// parserMain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "parser.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"Please input command\n";
	string input;
	cin>>input;

	Parser p = Parser();
	bool valid = p.validate(input);
	if(valid)
		cout<<"Command is valid.\n";
	else
		cout<<"Error: Command is NOT valid\n";
	return 0;
}

