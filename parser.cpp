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
		//tokens.push_back(start);
		tokens.push_ back(s);
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
	    string rel_name = takens.at(1);
		return true; 
	}
	if(close.compare(first) == 0)
	{
		// SID WU
		//What is the format of this command "Close"
		//need a flag in DBMS  to show which database has been opened
		string rel_name = takens.at(1);
		return true; 
	}
	if(write.compare(first) == 0)
	{
		// GRACE COFFMAN
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
		string rel_name = takens.at(1);
		return true; 
	}
	if(create.compare(first) == 0)
	{
		string* rel_name;
		string* primary_key;
		vector<Attribute>* attr_list;
		// SID WU
			if(tokens.at(1) == "TABLE")
		{
			//throw
			string rel_name = new string(tokens.at(2));
			
			int i = 3;
			
			if(tokens.at(i) != "(")
				//throw exception
			else
			{
				//a new attribute constructure funciton is needed
				attr_list = new vector<Attribute>;
				
				while(tokens.at(i + 1) != ")")
				{
					//case when input primary key 
					bool has_key = false;
					if(tokens.at(i + 1) == "PRIMARY" ) //input primary key
					{
						if(has_key == false)
						{
							i = i +2;
							primary_key = new string(tokens.at(i));
							key = key->substring(1, key.length - 2); //strip parenthesis
						}
						else // syntax error
						{
							//throw exception 
						}
					}

					//case when input attributes
					Attribute temp = Attribute(tokens.at(++i), tokens.at(++i));
					attr_list.push_back(temp);		

				if(tokens.at(i + 1) == ",")
					continue; // input next attribute
				else 
				{
					// case when we have some other key words.
				}
			}
		}
		else if(tokens.at(1) == "DATABASE")
		{
			string db_name = tokens.at(2);
		}
		else //Error operation
		{
		//	throw exception
		}
		return true; 
	}
	return false;
}