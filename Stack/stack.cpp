#include "stack.h"
#include <iostream>

using namespace std;

static const string LIST_EMPTY = "List is empty";

//////////////////////////////////////////////////////////////
// Public
//////////////////////////////////////////////////////////////

Stack::Stack()
{
	init();
}

Stack::Stack(const Stack &other)
{
	init();
	copy(other);
}

Stack Stack::operator=(const Stack &other)
{
	deleteAll();
	init();
	copy(other);
	return *this;
}

Stack::~Stack()
{
	deleteAll();
}


void Stack::push(string item)
{
	mList.addToFront(item);
}

void Stack::pop() throw(string)
{
	if (isEmpty() == true)
	{
		throw LIST_EMPTY;
	}
	mList.removeFront();
}

string Stack::getTop() const throw(string)
{	
	if (mList.getCount() == 0)
	{
		throw LIST_EMPTY;
	}
	
	string lists = mList.getFront();
	return lists;
}

bool Stack::isEmpty() const
{
	if (mList.getCount() <= 0)
	{
		return true;
	}
	else
	{
		return false;	
	}
}

//////////////////////////////////////////////////////////////
// Private
//////////////////////////////////////////////////////////////

void Stack::init()
{
	
}

void Stack::copy(const Stack & other)
{
	mList = other.mList;
}


void Stack::deleteAll()
{
	
}

//////////////////////////////////////////////////////////////
// Friends
//////////////////////////////////////////////////////////////

ostream & operator<<(ostream & os, const Stack & s)
{
	for (int i = 0; i < s.mList.getCount(); ++i)
	{
		cout << s.mList.getAt(i) << " ";
	}
	return os;
}
