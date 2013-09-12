/* 
    File: parser.cpp

    Authors: Grace Coffman, Sidian Wu, Wesley Tang
            Department of Computer Science
            Texas A&M University
			
    This file contains the implementation for database parser.

*/

#include "stdafx.h"
#include <vector> 
#include <string>
#include <iostream>
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
	//START TROUBLESHOOTING ITERATOR	
	/*
	for (int i = 0; i < tokens.size(); ++i) {
			cout << tokens[i];
	}
	*/
	//END TROUBLESHOOTING ITERATOR		

	return tokens;

}

//WE NEED A RECURSIVE DESCENT PARSER FOR PARSING AND HANDLING EXPRESSIONS 

bool Parser::validate(string input) {
	
	vector<string> tokens = tokenizer(input);
	string first = tokens[0];

	if(open.compare(first) == 0)
	{
		// SID WU
		return true; 
	}
	if(close.compare(first) == 0)
	{
		// SID WU
		return true; 
	}
	if(write.compare(first) == 0)
	{
		// GRACE COFFMAN
		return true; 
	}
	if(exit.compare(first) == 0)
	{
		// WES TANG
		printf("Exit command parsed.\n\n");
		// exit();
		return true; 
	}
	if(insert.compare(first) == 0)
	{
		// WES TANG
		return true; 
	}
	if( (del.compare(first) == 0) && (tokens[1] == "FROM") && (tokens[3] == "WHERE") && (tokens.size() > 4) )
	{
		printf("Delete command parsed.\n\n");
		string rel_name = tokens[2];
		tokens.erase(tokens.begin(), tokens.begin()+4);
		string expr;
		for (int i = 0; i < tokens.size(); ++i) {
			expr += tokens[i];
		}
		if (expr.back() == ';') {
			expr.erase(expr.end());
		}
		else {
			printf("Missing Semicolon.\n");
			return false;
		}
		cout << "expr == " << expr << endl;
		// SEND REMAINING VECTOR (WHICH SHOULD CONTAIN AN ATOMIC EXPRESSION)
		// TO BE PARSED RECURSIVELY INTO A TABLE AND THEN SUBTRACTED FROM
		// THE THE TABLE rel_name. ASSUMED ERROR CATCHING FOR EXPRESSION PASRING
		// TO BE HANDLED IN parse_expr. ??????????????????????????????
		// parse_expr(expr);
		// difference(table1, table2);

		return true; 
	}
	if(update.compare(first) == 0)
	{
		// GRACE COFFMAN
		return true; 
	}
	if(show.compare(first) == 0)
	{
		// SID WU
		return true; 
	}
	if(create.compare(first) == 0)
	{
		// SID WU
		return true; 
	}
	return false;
}