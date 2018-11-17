#include "queue.h"
#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////
// Public
//////////////////////////////////////////////////////////////

Queue::Queue()
{
	init();
}

Queue::Queue(const Queue & other)
{
	init();
	copyAll(other);
}

Queue Queue::operator=(const Queue & other)
{
	deleteAll();
	init();
	copyAll(other);
	return *this;
}

Queue::~Queue()
{
	deleteAll();
}

void Queue::add(string s)
{
	mList.add(s);
}

string Queue::remove()
{
	string s = mList.getFront();
	mList.remove(s);
	return s;
}

bool Queue::isEmpty() const
{
	return mList.isEmpty();
}

void Queue::init()
{

}

void Queue::copyAll(const Queue & other)
{
	mList = other.mList;
}

void Queue::deleteAll()
{

}

ostream & operator<<(ostream & os, const Queue & q)
{
	for (int i = 0; i < q.mList.getCount(); ++i)
	{
		cout << q.mList.getAt(i) << " ";
	}
	return os;
}
