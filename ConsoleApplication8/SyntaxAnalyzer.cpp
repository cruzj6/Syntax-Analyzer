#include "SyntaxAnalyzer.h"


int main() {
	
	SyntaxAnalyzer SyntaxAnalyzer; 
}


SyntaxAnalyzer::SyntaxAnalyzer()
{
	if (lexer.openFile()) {
		lexer.getChar();
		
		nextToken = lexer.lex();
		cout << "Deriving how your class is going from code: \n";
		//cout << "First token is: " << nextToken << "\n";
		taking_a_class();
	}
}


SyntaxAnalyzer::~SyntaxAnalyzer()
{
}

void SyntaxAnalyzer::taking_a_class() {
	
	
		cout << "You are taking a class" << endl;
		if (nextToken == I_need_a)
			classwork();
		if (nextToken == Homework_is_due)
		homework();
}


void SyntaxAnalyzer::classwork()
{
	cout << "You are doing classwork!" << endl;
	solo_work();
	participation_grade();
}

void SyntaxAnalyzer::school_thing()
{
	
	if (nextToken == pencil || nextToken == pen || nextToken == ruler || nextToken == calculator
		|| nextToken == notebook || nextToken == laptop || nextToken == professor || nextToken == book)
	{

		cout << "You are using "<< suppliesctr << " tool(s) for your schoolwork!" << endl;
		suppliesctr++;
		nextToken = lexer.lex();
	}
	else{
		cout << "ERROR!!! : Expected a school_thing" << endl;
		if (cin.get())
		{
			exit(0);
		}
	}
}

void SyntaxAnalyzer::grade()
{
	if (nextToken == A || nextToken == B || nextToken == C || nextToken == D || nextToken == E || nextToken == F)

	{
		cout << "You gave a grade in your code!" << endl;
		nextToken = lexer.lex();
	}
	else{
		cout << "ERROR!!! : Expected a grade (A,B,C,D,E,F)" << endl;
		if (cin.get())
		{
			exit(0);
		}
	}
}

void SyntaxAnalyzer::quality()
{
	if (nextToken == great ||  nextToken == efficient || nextToken == useful || nextToken == reflective)
	{
		cout << "By your opinion of this it sounds like you do good work! Yay!" << endl;
		nextToken = lexer.lex();
	}
	else if (nextToken == bad)
	{
		cout << "You expressed the quality of your work needs improvement! Yay for honesty!";
		nextToken = lexer.lex();
	}
	else{
		cout << "ERROR!!! : Expected <quality> identifier" << endl;
		if (cin.get())
		{
			exit(0);
		}
	}
	}

void SyntaxAnalyzer::solo_work()
{
	if (nextToken == I_need_a)
	{
		cout << "You do some work in the classroom!, for this you use some tools:" << endl;
		nextToken = lexer.lex();
		school_thing();

		if (nextToken == and)
		{
			while (nextToken == and)
			{
				nextToken = lexer.lex();
				school_thing();
			}
		}

		if (nextToken == for_my)
		{
			nextToken = lexer.lex();
			solo_respons();
		}
		else{
			cout << "ERROR!!! : Expected for_my" << endl;
			if (cin.get())
			{
				exit(0);
			}
		}

	}
	else{
		cout << "ERROR!!! : Expected I_need_a" << endl;
		if (cin.get())
		{
			exit(0);
		}
	}

}

void SyntaxAnalyzer::solo_respons()
{
	quality();
	solo_class_actions();
}

void SyntaxAnalyzer::solo_class_actions()
{
	if (nextToken = notes || nextToken == writing || nextToken == problems || nextToken == answers || nextToken == questions)
	{
		cout << "You did stuff in class!" << endl;
		nextToken = lexer.lex();
	}
}

void SyntaxAnalyzer::participation_grade()
{
	if (nextToken == I_have_a)
	{
		cout << "You have a grade in participation!" << endl;
		nextToken = lexer.lex();
		grade();

		
	}

	else
		
	{
		cout << "ERROR!!! : Expected I_have_a" << endl;
	
		if (cin.get())
		{
			exit(0);
		}
	}

	if (nextToken == in_participation)
	{
		nextToken = lexer.lex();
		if (nextToken == my_grade_is)
		{
			cout << "Youre going to tell us what you think of your grade!" << endl;
			nextToken = lexer.lex();
			quality();
		}
	}

	else{
		cout << "ERROR!!! : Expected in_participation" << endl;
		if (cin.get())
		{
			exit(0);
		}
	}
}

void SyntaxAnalyzer::homework()
{
	hw_properties();
	if (nextToken == also)
	{
		nextToken = lexer.lex();
		what_hw_is();
		nextToken = lexer.lex();
	}
	else{
		cout << "ERROR!!! : Expected also" << endl;
		if (cin.get())
		{
			exit(0);
		}
	}
	}

void SyntaxAnalyzer::hw_properties()
{
	due();
	if (nextToken == it_is)
	{
		nextToken = lexer.lex();
		quality();
	}
	else{
		cout << "ERROR!!! : Expected it_is" << endl;
		if (cin.get())
		{
			exit(0);
		}
	}
}

void SyntaxAnalyzer::due()
{
	if (nextToken == Homework_is_due)
	{
		nextToken = lexer.lex();
		day();
		
		if (nextToken == and)
		{
			while (nextToken == and)
			{
				nextToken = lexer.lex();
				day();
				
			}

		}
		if (nextToken == Turned_Homework_in)
		{
			cout << "Good you turned in your homework!" << endl;
			nextToken = lexer.lex();
			day();
			
		}
	}

	else
	{
		cout << "ERROR!!! : Expected Homework_is_due" << endl;
		if (cin.get())
		{
			exit(0);
		}
	}
}

void SyntaxAnalyzer::day()
{
	if (nextToken == tomorrow || nextToken == Monday ||  nextToken == Tuesday|| nextToken == Wednesday || nextToken == Thursday || nextToken == Friday)
	{
		//cout << "cool day!" << endl;
		nextToken = lexer.lex();
	}
	else{
		cout << "ERROR!!! : Expected a day of the week after and" << endl;
		if (cin.get())
		{
			exit(0);
		}
	}
	}

void SyntaxAnalyzer::what_hw_is()
{
	if (nextToken == It_is)
	{
		nextToken = lexer.lex();
		hw_type();
		

		if (nextToken == requiring)
		{
			nextToken = lexer.lex();
			school_thing();
		}

		else{
			cout << "ERROR!!! : Expected requiring" << endl;
			if (cin.get())
			{
				exit(0);
			}
		}
	}

	else{
		cout << "ERROR!!! : Expected It_is" << endl;
		if (cin.get())
		{
			exit(0);
		}
	}

	
}

void SyntaxAnalyzer::hw_type()
{
	if (nextToken == project || nextToken == paper || nextToken == exercises)
	{
		cout << "You have some type of homework!" << endl;
		nextToken = lexer.lex();
	}
	else{
		cout << "ERROR!!! : Expected a hw_type terminal" << endl;
		if (cin.get())
		{
			exit(0);
		}
	}
}