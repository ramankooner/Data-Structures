#include <iostream>
#include <string>
using namespace std;

#include "stack.h"

static string getAns(bool value)
{
	if (value) return "Yes";
	else return "No";
}

void main()
{
	Stack s1;
	s1.push("a");
	s1.push("b");
	s1.push("c");

	Stack s2(s1);
	s2.push("1");
	s2.push("2");
	s2.push("3");

	Stack s3;
	s3 = s1;
	s3.push("d");
	s3.push("e");
	s3.push("f");

	Stack *s4 = new Stack(s3);
	s4->push("dog");
	s4->push("cat");
	delete s4;

	cout << "s1: " << s1 << endl;
	cout << endl << "s2: " << s2 << endl;
	cout << endl << "s3: " << s3 << endl;

	cout << "Top(s1) = " << s1.getTop() << ", isEmpty(s1) = " << getAns(s1.isEmpty()) << endl;
	cout << "Top(s2) = " << s2.getTop() << ", isEmpty(s2) = " << getAns(s2.isEmpty()) << endl;
	cout << "Top(s3) = " << s3.getTop() << ", isEmpty(s3) = " << getAns(s3.isEmpty()) << endl;

	while (!s2.isEmpty())
	{
		string s = s2.getTop();
		s2.pop();
		s1.push(s);
	}

	while (!s3.isEmpty())
	{
		string s = s3.getTop();
		s3.pop();
		s1.push(s);
	}

	cout << endl << "s1: " << s1 << "   isEmpty(s1) = " << getAns(s1.isEmpty()) << endl;
	cout << endl << "s2: " << s2 << "   isEmpty(s2) = " << getAns(s2.isEmpty()) << endl;
	cout << endl << "s3: " << s3 << "   isEmpty(s3) = " << getAns(s3.isEmpty()) << endl;

	cout << endl;

	try
	{
		s2.getTop();
		cout << "Missed throw" << endl;
	}
	catch (string s)
	{
		cout << "Caught: " << s << endl;
	}

	try
	{
		s2.pop();
		cout << "Missed throw" << endl;
	}
	catch (string s)
	{
		cout << "Caught: " << s << endl;
	}

	cout << "Pause: "; char a; cin >> a;

}