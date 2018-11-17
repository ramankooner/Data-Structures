#include <iostream>
using namespace std;

#include "utility.h"

void main()
{
	Utility U;

	cout << "Reverse of empty string is " << U.reverse("") << endl;
	cout << "Reverse of <a> is " << U.reverse("a") << endl;
	cout << "Reverse of <ab> is " << U.reverse("ab") << endl;
	cout << "Reverse of <abcde> is " << U.reverse("abcde") << endl;

	cout << "factorial(0) is " << U.factorial(0) << endl;
	cout << "factorial(1) is " << U.factorial(1) << endl;
	cout << "factorial(10) is " << U.factorial(10) << endl;

	cout << "countOccurances(a, ) is " << U.countOccurances('a', "") << endl;
	cout << "countOccurances(a, x) is " << U.countOccurances('a', "x") << endl;
	cout << "countOccurances(a, xyz) is " << U.countOccurances('a', "xyz") << endl;
	cout << "countOccurances(a, xabaca) is " << U.countOccurances('a', "xabaca") << endl;

	cout << "isPalindrome() is " << ((U.isPalindrome("")) ? "Yes" : "No") << endl;
	cout << "isPalindrome(a) is " << ((U.isPalindrome("a")) ? "Yes" : "No") << endl;
	cout << "isPalindrome(xx) is " << ((U.isPalindrome("xx")) ? "Yes" : "No") << endl;
	cout << "isPalindrome(xy) is " << ((U.isPalindrome("xy")) ? "Yes" : "No") << endl;
	cout << "isPalindrome(radar) is " << ((U.isPalindrome("radar")) ? "Yes" : "No") << endl;
	cout << "isPalindrome(turkey) is " << ((U.isPalindrome("turkey")) ? "Yes" : "No") << endl;

	cout << "gcd(1,1) is " << U.gcd(1, 1) << endl;
	cout << "gcd(32452867,860281211) is " << U.gcd(32452867, 86028121) << endl;;
	cout << "gcd(125,4000) is " << U.gcd(125, 4000) << endl;;
	
	cout << "mult(0,4) is " << U.mult(0, 4) << endl;;
	cout << "mult(4,0) is " << U.mult(4, 0) << endl;;
	cout << "mult(5,25)) is " << U.mult(5, 25) << endl;;
	cout << "\ntowers(0) is:" << endl;
	U.towers(0);

	cout << "\ntowers(1) is:" << endl;
	U.towers(1);
	
	cout << "\ntowers(4) is:" << endl;
	U.towers(4);

	cout << "OK "; char a; cin >> a;

}