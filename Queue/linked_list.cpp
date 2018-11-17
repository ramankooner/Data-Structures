#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#include "linked_list.h"

static const string Missing = "String not found";
static const string OutOfRange = "Index out of range";
static const string ListEmpty = "List is empty";

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helper
///////////////////////////////////////////////////////////////////////////////////////////////////////////
static bool isEqual(string s1, string s2)
{
	return !s1.compare(s2);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Public
///////////////////////////////////////////////////////////////////////////////////////////////////////////
LinkedList::LinkedList()
{
	init();
}

LinkedList::LinkedList(vector<string> &strings)
{
	init();
	for (unsigned int ii = 0; ii < strings.size(); ++ii)
	{
		add(strings.at(ii));
	}
}

LinkedList::LinkedList(const LinkedList &other)
{
	init();
	copyAll(other);
}

LinkedList LinkedList::operator=(const LinkedList &other)
{
	deleteAll();
	init();
	copyAll(other);

	return *this;
}

LinkedList::~LinkedList()
{
	deleteAll();
}

void LinkedList::add(string element)
{
	addToRear(element);
}

void LinkedList::addToFront(string element)
{
	addAt(element, 0);
}

void LinkedList::addToRear(string element)
{
	Node *newNode = new Node(element);
	newNode->mNext = mRear;
	newNode->mPrevious = mRear->mPrevious;
	newNode->mPrevious->mNext = newNode;
	newNode->mNext->mPrevious = newNode;
}

void LinkedList::addAt(string element, int index) throw(string)
{
	if (index < 0 || index > getCount()) throw OutOfRange;

	Node *current = mFront;
	for (int ii = 0; ii < index; ++ii)
	{
		if (current->mNext != mRear) current = current->mNext;
	}

	Node *newNode = new Node(element);
	newNode->mPrevious = current;
	newNode->mNext = current->mNext;
	newNode->mPrevious->mNext = newNode;
	newNode->mNext->mPrevious = newNode;
}

void LinkedList::addBefore(string elementToAdd, string elementToAddBefore)
{
	int index = find(elementToAddBefore);
	if (index == -1) throw Missing;

	addAt(elementToAdd, index);

}

void LinkedList::addAfter(string elementToAdd, string elementToAddAfter)
{
	int index = find(elementToAddAfter);
	if (index == -1) throw Missing;

	addAt(elementToAdd, index + 1);
}

string LinkedList::getAt(int index) const
{
	if (index < 0 || index >= getCount()) throw OutOfRange;

	Node *current = mFront->mNext;
	for (int ii = 0; ii < index; ++ii)
	{
		current = current->mNext;
	}

	return current->mData;
}

string LinkedList::getFront() const
{
	if (isEmpty()) throw ListEmpty;
	return mFront->mNext->mData;
}

string LinkedList::getRear() const
{
	if (isEmpty()) throw ListEmpty;
	return mRear->mPrevious->mData;
}

void LinkedList::remove(string element)
{
	int index = find(element);
	if (index == -1) throw Missing;

	removeAt(index);
}

void LinkedList::removeFront()
{
	if (isEmpty()) throw ListEmpty;
	removeAt(0);
}

void LinkedList::removeRear()
{
	if (isEmpty()) throw ListEmpty;
	removeAt(getCount() - 1);
}

void LinkedList::removeAt(int index)
{
	if ((getCount() < index))
	{
		throw OutOfRange;
	}

	Node *current = mFront->mNext;
	int i = 0;
	while (i != index)
	{
		current = current->mNext;
		i++;
	}
	Node *previous = current->mPrevious;
	previous->mNext = current->mNext;
	current->mNext->mPrevious = previous;
	delete current;

}

vector<string> LinkedList::toVector(bool sorted) const
{
	vector<string> result;

	Node *current = mFront->mNext;
	while (current != mRear)
	{
		result.push_back(string(current->mData));
		current = current->mNext;
	}

	if (sorted) sort(result.begin(), result.end());

	return result;
}

LinkedList LinkedList::operator+(const LinkedList &other)
{
	LinkedList sum(*this);

	Node *current = other.mFront->mNext;
	while (current != other.mRear)
	{
		sum.add(current->mData);
		current = current->mNext;
	}

	return sum;
}

LinkedList LinkedList::operator-(const LinkedList &other)
{
	LinkedList diff(*this);

	Node *current = other.mFront->mNext;
	while (current != other.mRear)
	{
		if (diff.isPresent(current->mData)) diff.remove(current->mData);
		current = current->mNext;
	}

	return diff;
}

bool LinkedList::operator==(const LinkedList &other)
{
	if (getCount() != other.getCount()) return false;

	Node *c1 = mFront->mNext;
	Node *c2 = other.mFront->mNext;

	while (c1 != mRear)
	{
		if (!isEqual(c1->mData, c2->mData)) return false;
		c1 = c1->mNext;
		c2 = c2->mNext;
	}

	return true;

}

int LinkedList::getCount() const
{
	int count = 0;
	Node *current = mFront->mNext;
	while (current != mRear)
	{
		++count;
		current = current->mNext;
	}

	return count;
}

bool LinkedList::isEmpty() const
{
	return (mFront->mNext == mRear);
}

bool LinkedList::isPresent(string element) const
{
	if (find(element) == -1) return false;
	else return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Friends
///////////////////////////////////////////////////////////////////////////////////////////////////////////
ostream &operator<<(ostream &os, const LinkedList &list)
{
	vector<string> vlist = list.toVector(false);

	for (unsigned int ii = 0; ii < vlist.size(); ++ii)
	{
		os << vlist.at(ii) << " ";
	}

	return os;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Private
///////////////////////////////////////////////////////////////////////////////////////////////////////////
int LinkedList::find(string s) const
{
	int indx = 0;
	Node *current = mFront->mNext;
	while (current != mRear)
	{
		if (isEqual(current->mData, s)) return indx;
		++indx;
		current = current->mNext;
	}

	return -1;
}

void LinkedList::init()
{
	mFront = new Node("DUMMYFRONT");
	mRear = new Node("DUMMYREAR");
	mFront->mNext = mRear;
	mRear->mPrevious = mFront;
}

void LinkedList::copyAll(const LinkedList &other) // not DUMMYs - only client added data elements
{
	Node *current = other.mFront->mNext;
	while (current != other.mRear)
	{
		add(current->mData);
		current = current->mNext;
	}
}

void LinkedList::deleteAll() // Including DUMMYs
{
	Node *current = mFront;
	while (current != 0)
	{
		Node *next = current->mNext;
		delete current;
		current = next;
	}
	mFront = mRear = 0;
}




