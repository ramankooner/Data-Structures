#include "utility.h"
#include "stack.h"
#include <string>
#include <iostream>
using namespace std;

int moveCount = 0;
void solve(Stack &from, Stack &to, Stack &temp, int n, int &moveCount);
void move(Stack &from, Stack &to, int &moveCount);

Utility::Utility()
{

}

string Utility::reverse(string s)
{
	if (s.length() <= 1) return s;
	else return s.back() + reverse(s.substr(0, s.length() - 1));
}

int Utility::factorial(int n)
{
	if (n <= 1) return n;
	else 
	{
		return n * factorial(n - 1);
	}
}

int Utility::countOccurances(char a, string s)
{
	if (s.length() == 0) return 0;

	else if (s.length() == 1) return ((a == s[0]) ? 1 : 0);

	else if (a == s[0]) return 1 + countOccurances(a, s.substr(1, s.length() - 1));

	else return 0 + countOccurances(a, s.substr(1, s.length() - 1));

}

bool Utility::isPalindrome(string s)
{
	if (s.length() <= 1) return true;
	else if (s[0] != s[s.length() - 1]) return false;
	else return isPalindrome(s.substr(1, s.length() - 2));
}

int Utility::gcd(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a == b)
		return b;
	else
		return gcd(b, a % b);
}

int Utility::mult(int a, int b)
{
	if (a == 0) return 0;
	if (a == 1) return b;
	if (b == 0) return 0;
	if (b == 1) return a;

	else return (a + mult(a, b - 1));
} 

void Utility::towers(int n)
{
	moveCount = 0;
	Stack tower1("Tower 1");
	Stack tower2("Tower 2");
	Stack tower3("Tower 3");
	cout << "TowersOfHanoi(" << n << ")" << endl;

	for (int i = n; i > 0; --i)
	{
		tower1.push(i);
	}

	solve(tower1, tower2, tower3, n, moveCount);

	if (n > 0)
	{
		cout << "Required " << moveCount << " moves" << endl;
	}
}

void solve(Stack &from, Stack &to, Stack &temp, int n, int &moveCount)
{
	if (n == 0) return;
	else if (n == 1) move(from, to, moveCount);
	else
	{
		solve(from, temp, to, n - 1, moveCount);
		move(from, to, moveCount);
		solve(temp, to, from, n - 1, moveCount);
	}

}

void move(Stack &from, Stack &to, int &moveCount)
{
	int top = from.getTop();
	from.pop();
	to.push(top);

	++moveCount;
	cout << "Move " << top << " from Stack " << from.getName() << " to Stack " << to.getName() << endl;

}


