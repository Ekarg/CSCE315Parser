#include "stdafx.h"
#include <vector> 
#include <string>
#include "parser.h"
using namespace std;

vector<string> Parser::tokenizer(string line) {
	char* str = new char[line.length()+1];
	char* next = NULL;
	vector<string> tokens;
	for(int i=0; i<(int)line.length(); i++)
		str[i]=line.at(i);
	str[line.length()]=NULL;
	char * start = NULL;
	start = strtok_s(str, " ", &next);
	while(start!=NULL)
	{
		string s(start);
		tokens.push_back(start);
		start = strtok_s(NULL, " ", &next);
	}
	return tokens;

}

bool Parser::validate(string input) {
	
	vector<string> tokens = tokenizer(input);
	string first = tokens[0];

	if(open.compare(first) == 0)
	{

	}
	if(close.compare(first) == 0)
	{

	}
	if(write.compare(first) == 0)
	{

	}
	if(exit.compare(first) == 0)
	{

	}
	if(insert.compare(first) == 0)
	{

	}
	if(del.compare(first) == 0)
	{

	}
	if(update.compare(first) == 0)
	{

	}
	if(show.compare(first) == 0)
	{

	}
	if(create.compare(first) == 0)
	{

	}
	return false;
}