#pragma once
#include "Lexer.h"


class SyntaxAnalyzer
{
	Lexer lexer;
	int nextToken;
	string comperror[100];
	string* comperrorptr;
	//comperrorptr = comperror;
	int comperrorlen;
	int suppliesctr = 1;
	

public:
	SyntaxAnalyzer();
	~SyntaxAnalyzer();

	void taking_a_class();
	void school_thing();
	void grade();
	void quality();

	void classwork();
	void solo_work();
	void solo_respons();
	void solo_class_actions();
	void participation_grade();

	void homework();
	void hw_properties();
	void due();
	void day();
	void what_hw_is();
	void hw_type();
	int getcomperrorlen();
	
};


