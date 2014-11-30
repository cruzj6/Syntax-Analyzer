#include "Lexer.h"


/*int main(void) {
Lexer lexer;
int token;
if (lexer.openFile()) {
lexer.getChar();
do {
token = lexer.lex();
} while (token != EOF);
}
}*/


Lexer::Lexer(void)
{
	fillSpecialWords();
}

Lexer::~Lexer(void)
{
	closeFile();
}


bool Lexer::openFile() {
	file.open("input.txt");
	if (!file.is_open()) {
		printf("ERROR - cannot open input.txt \n");
		return false;
	}
	return true;
}

 
void Lexer::closeFile() {
	file.close();
	system("pause"); 
}

void Lexer::fillSpecialWords() {
	//cout << "Filling in special words map object\n";

	specialWord[string("pencil")] = 8;
	specialWord[string("pen")] = 9;
	specialWord[string("ruler")] = 10;
	specialWord[string("calculator")] = 11;
	specialWord[string("notebook")] = 12;
	specialWord[string("laptop")] = 13;
	specialWord[string("professor")] = 14;
	specialWord[string("book")] = 15;
	specialWord[string("A")] = 16;
	specialWord[string("B")] = 17;
	specialWord[string("C")] = 18;
	specialWord[string("D")] = 19;
	specialWord[string("E")] = 20;
	specialWord[string("F")] = 21;
	specialWord[string("great")] = 22;
	specialWord[string("bad")] = 23;
	specialWord[string("efficient")] = 24;
	specialWord[string("useful")] = 25;
	specialWord[string("reflective")] = 26;

	specialWord[string("I_need_a")] = 27;
	specialWord[string("for_my")] = 28;
	specialWord[string("notes")] = 29;
	specialWord[string("writing")] = 30;
	specialWord[string("problems")] = 31;

	specialWord[string("answers")] = 32;
	specialWord[string("questions")] = 33;
	specialWord[string("I_have_a")] = 34;
	specialWord[string("in_participation")] = 35;
	specialWord[string("and")] = 36;
	specialWord[string("my_grade_is")] = 37;
	
	specialWord[string("it_is")] = 38;
	specialWord[string("Homework_is_due")] = 39;
	specialWord[string("Turned_homework_in")] = 40;
	specialWord[string("tomorrow")] = 41;
	specialWord[string("Monday")] = 42;
	specialWord[string("Tuesday")] = 43;
	specialWord[string("Wednesday")] = 44;
	specialWord[string("Thursday")] = 45;
	specialWord[string("Friday")] = 46;
	specialWord[string("It_is")] = 47;
	specialWord[string("requiring")] = 48;
	specialWord[string("project")] = 49;
	specialWord[string("paper")] = 50;
	specialWord[string("exercises")] = 51;
	specialWord[string("also")] = 52;
}

int Lexer::lookup(char ch) {
	switch (ch) { 
	case '.':
		addChar();
		nextToken = PERIOD;
		break;
	case '!':
		addChar();
		nextToken = EXCLAMATION;
		break;
	case ',':
		addChar();
		nextToken = COMMA;
		break;
	case '_':
		addChar();
		nextToken = UNDERSCORE;
		break;
	default:
		addChar();
		nextToken = EOF;
		break;
	}
	return nextToken;
}


void Lexer::addChar() {
	if (lexLen <= 98) {
		//cout << "Character " << nextChar << " placed at index " << lexLen << "\n";
		lexeme[lexLen++] = nextChar;
		lexeme[lexLen] = 0;
	}
	else
		printf("Error - lexeme is too long \n");
}




void Lexer::getChar() {

	if (file.good()) {
		nextChar = file.get();
		//cout << "Next character:" << nextChar << "|" << endl;

		if (isalpha(nextChar))
			charClass = LETTER;
		else if (isdigit(nextChar))
			charClass = DIGIT;
		else if (nextChar == '_')
			charClass = UNDERSCORE;
		else
			charClass = UNKNOWN;
	}
	else
		charClass = EOF;
}



void Lexer::getNonBlank() {
	while (isspace(nextChar))
		getChar();
}

 
int Lexer::lex() {
	//cout << "LEX\n";

	lexLen = 0;
	getNonBlank();	

	switch (charClass) {
	
	case LETTER:
		addChar();
		getChar();
		while (charClass == LETTER || charClass == DIGIT || charClass == UNDERSCORE) {
			addChar();
			getChar();
		}
		nextToken = specialWord[string(lexeme)];
		break;

		
	case DIGIT:
		addChar();
		getChar();
		while (charClass == DIGIT) {
			addChar();
			getChar();
		}
		nextToken = INT_LIT;
		break;

		
	case UNKNOWN:
		lookup(nextChar);
		getChar();
		break;

	case EOF:
		nextToken = EOF;
		lexeme[0] = 'E';
		lexeme[1] = 'O';
		lexeme[2] = 'F';
		lexeme[3] = 0;
		
		break;
	} 

	if (nextToken == EOF)
	{
		//for (int i = comperrorlen ; i >= 0; i--)
		//{
		//	//cout << "Compile Errors: \n" << comperror[i];

		//}
		cout << "\nYour lexeme is perfect! Press Enter key to exit!";
		if (cin.get())
		{
			
			exit(0);
		}
	}
	//cout<< "lexeme: " << lexeme << "\ntoken is " << nextToken << endl;
	return nextToken;

	
}


