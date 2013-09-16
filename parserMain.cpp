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
#include <fstream>
#include "parser.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	string line;
	ifstream input("testInput.txt");
	ofstream output ("output.txt");

	if(input.is_open() && output.is_open())
	{
		cout<<"******Writing output to output.txt\n";
		while (getline(input, line)) {
			cout<<"\n\nCommand: "<<line<<"\n";
			output<<"\n\nCommand: "<<line<<"\n";
			//cin>>input;			
			if(input == "Hello_World") {
				break;
			}
			Parser p = Parser();
			bool valid = p.validate(line);
			if(valid)
			{
				cout<<"Command is valid.\n";
				output<<"Command is valid.\n";
			}
			else
			{
				cout<<"Error: Command is NOT valid\n";
				output<<"Error: Command is NOT valid\n";
			}
		}
		output.close();
	}
	while (true) {
		cout<<"\n\nPlease input Command\n";
		string input;
		//cin>>input;
		getline(cin, input);
		if(input == "Hello_World") {
			break;
		}
		Parser p = Parser();
		bool valid = p.validate(input);
		if(valid)
		{
			cout<<"Command is valid.\n";			
		}
		else
		{
			cout<<"Error: Command is NOT valid\n";				
		}
	}

	return 0;
}

