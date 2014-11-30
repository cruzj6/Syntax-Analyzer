
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <map>

#define IDENT 0
#define LETTER 1
#define DIGIT 2
#define UNDERSCORE 3
#define INT_LIT 4
#define PERIOD 5
#define EXCLAMATION 6
#define COMMA 7

#define pencil 8
#define pen 9
#define ruler 10
#define calculator 11
#define notebook 12
#define laptop 13
#define professor 14
#define book 15
#define A 16
#define B 17
#define C 18
#define D 19
#define E 20
#define F 21
#define great 22
#define bad 23
#define efficient 24
#define useful 25
#define reflective 26

#define I_need_a 27
#define for_my 28
#define notes 29
#define writing 30
#define problems 31
#define answers 32
#define questions 33
#define I_have_a 34
#define in_participation 35
#define and 36
#define my_grade_is 37
#define it_is 38
#define Homework_is_due 39
#define Turned_Homework_in 40
#define tomorrow 41
#define Monday 42
#define Tuesday 43
#define Wednesday 44
#define Thursday 45
#define Friday 46
#define It_is 47
#define requiring 48
#define project 49
#define paper 50
#define exercises 51
#define also 52
#define EOF 98

#define UNKNOWN 99

using namespace std;

class Lexer
{
	int charClass;
	char lexeme[100];
	char nextChar;
	int lexLen;
	int token;
	string error[100];
	int errorlen = 0;
	int nextToken;
	ifstream file;
	map <string, int> specialWord;
	

public:
	Lexer(void);
	~Lexer(void);

	void addChar();
	void adderror();
	void adderrorlen();
	void getChar();
	void getNonBlank();
	bool openFile();
	void closeFile();
	void fillSpecialWords();
	int lex();
	int lookup(char ch);
	

};