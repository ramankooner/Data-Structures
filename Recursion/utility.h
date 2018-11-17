#ifndef UTILITY_H
#define UTILITY_H

#include <string>
using namespace std;

class Utility
{
public:
	Utility();
	string reverse(string s);
	int factorial(int n);
	int countOccurances(char a, string s);
	bool isPalindrome(string s);
	int gcd(int a, int b);
	int mult(int a, int b);
	void towers(int n);
};


#endif
