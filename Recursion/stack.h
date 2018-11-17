#ifndef STACK_H
#define STACK_H

#include <stack>
#include <string>
using namespace std;

class Stack
{
public:
	Stack(string name);
	string getName() const;
	int getTop() const;
	void pop();
	void push(int item);


private:
	string mName;
	stack<int> mStack;
};
#endif
