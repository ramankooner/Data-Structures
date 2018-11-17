#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

#include "stack.h"
#include "queue.h"

static vector<string> getInput()
{
	vector<string> input;
	input.push_back("( 1 + 2 )");
	input.push_back("( ( 1 + 2 )");
	input.push_back("( 3 + ( 22 / 7 ) )");
	input.push_back("( ( 3 + 4 ) * 5 )"); 
	input.push_back("( ( 1 / 3 ) * ( 6 / 2 ) )");
	
	return input;

}

static vector<string> tokenize(string expression)
{
	vector<string> tokens;

	unsigned int pos = 0;
	while (pos < expression.size())
	{
		while (pos < expression.size() && expression.at(pos) == ' ') ++pos;

		string token;
		while (pos < expression.size() && expression.at(pos) != ' ')
		{
			token.push_back(expression.at(pos));
			++pos;
		}
		tokens.push_back(token);
	}

	return tokens;
}

static bool isOperator(string s)
{
	return	(s.compare("+") == 00) ||
			(s.compare("-") == 00) ||
			(s.compare("*") == 00) ||
			(s.compare("/") == 00);
}

static Queue getPostFix(vector<string> tokens)
{
	Queue postFix;
	Stack operators;

	for (unsigned int ii = 0; ii < tokens.size(); ++ii)
	{
		string token = tokens.at(ii);

		if (token.compare("(") == 0)
		{
			operators.push("(");
		}
		else if (isOperator(token))
		{
			operators.push(token);
		}
		else if (token.compare(")") == 0)
		{
			while (operators.getTop().compare("(") != 0)
			{
				string opr = operators.getTop();
				operators.pop();
				postFix.add(opr);
			}
			operators.pop();
		}
		else // operand
		{
			postFix.add(token);
		}
	}
	
	return postFix;
}

static string eval(string opr, string op1, string op2)
{
	double x = stod(op1, 0);
	double y = stod(op2, 0);
	double z = 0.0;

	if (opr.compare("+") == 0) z = x + y;
	else if (opr.compare("-") == 0) z = x - y;
	else if (opr.compare("*") == 0) z = x * y;
	else z = x / y;

	ostringstream strs;
	strs << z;

	return strs.str();
}

static double evaluate(Queue postFix)
{
	Stack s;

	while (!postFix.isEmpty())
	{
		string token = postFix.remove();

		if (!isOperator(token)) s.push(token);
		else
		{
			string op2 = s.getTop();
			s.pop();

			string op1 = s.getTop();
			s.pop();

			s.push(eval(token, op1, op2));
		}
	}

	return stod(s.getTop(), 0);
}

static bool isBalanced(string s)
{
	Stack stack;

	for (unsigned int ii = 0; ii < s.size(); ++ii)
	{
		if (s.at(ii) == '(') stack.push("a");
		else if (s.at(ii) == ')')
		{
			if (stack.isEmpty()) return false;
			stack.pop();
		}
	} 
	return stack.isEmpty();
}

int main(int argc, char **argv)
{
	vector<string> input = getInput();

	for (unsigned int ii = 0; ii < input.size(); ++ii)
	{
		string expression = input.at(ii);
		cout << endl << "Expression: " << expression << endl;

		if (!isBalanced(expression))
		{
			cout << "* * * Parentheses are unbalanced * * *" << endl;
			continue;
		}

		vector<string> tokens = tokenize(expression);
		cout << "Tokens: ";
		for (unsigned int jj = 0; jj < tokens.size(); ++jj) cout << " " << tokens.at(jj);
		cout << endl;

		Queue postFix = getPostFix(tokens);
		cout << "Postfix: " << postFix << endl;

		cout << "Value: " << evaluate(postFix) << endl << endl;
	}

	char a; cout << "Pause: "; cin >> a;

	return 0;
}
