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
		if(tokens.size() != 2)
			return false;
		if(tokens[1].back()!=';')
			return false;
		return true; 
	}
	if(exit.compare(first) == 0)
	{
		printf("Exit command parsed.\n\n");
		// exit();
		return true; 
	}
	if( (insert.compare(first) == 0) && (tokens[1] == "INTO") && (tokens[3] == "VALUES") && (tokens[4] == "FROM") && (tokens.size() > 5) )
	{
		string rel_name = tokens[2];
		tokens.erase(tokens.begin(), tokens.begin()+5);
		// Case for "INSERT INTO points VALUES FROM RELATION (select (z2 > 0) dots_to_points);"
		if (tokens[0] == "RELATION") {
			tokens.erase(tokens.begin());
			string expr;
			for (int i = 0; i < tokens.size(); ++i) {
				expr += tokens[i];
			}
			if (expr.back() == ';') {
				expr.pop_back();
			}
			else {
				printf("Missing Semicolon.\n");
				return false;
			}
			cout << "expr == " << expr << endl;
			//parse_expr(expr);
			//union(table1, table2);
		}
		// Case for "INSERT INTO dots VALUES FROM (0, 0, 0);"
		else {
			string expr;
			for (int i = 0; i < tokens.size(); ++i) {
				expr += tokens[i];
			}
			if (expr.back() == ';') {
				expr.pop_back();
			}
			else {
				printf("Missing Semicolon.\n");
				return false;
			}
			vector<string> args;
			for (int j = 0; j < expr.size(); ++j) {
				if (expr[j] == '(') {
					continue;
				}
				if (expr[j] == '"') {
					continue;
				}
				string a;
				while ( (expr[j] != ',') && (j < expr.size()) && (expr[j] != ')') ) {
					a += expr[j];
					++j;
				}
				args.push_back(a);
			}
			for (int k = 0; k < tokens.size(); ++k) {
				cout << args[k] << endl;
			}
			//create entity with values from args
			//check if entity is allowable into table rel_name
			//insert entity into tablr rel_name
		}
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