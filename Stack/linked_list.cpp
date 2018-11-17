#include <vector>
#include <string>
#include "linked_list.h"
#include <algorithm>

using namespace std;

static const string IND_RANG = "Index out of range";
static const string NOT_FOUND = "String not found";
static const string LIST_EMPTY = "List is empty";
//////////////////////////////////////////////////////////////
// Public
//////////////////////////////////////////////////////////////

LinkedList::LinkedList()
{
	init();
}

LinkedList::LinkedList(vector<string> &strings)
{
	init();
	for (size_t i = 0; i < strings.size(); ++i)
	{
		add(strings.at(i));
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
	Node *nNode = new Node(element);
	nNode->mNext = mRear;
	nNode->mPrevious = mRear->mPrevious;
	nNode->mNext->mPrevious = nNode;
	nNode->mPrevious->mNext = nNode;

}

void LinkedList::addToFront(string element)
{
	addAt(element, 0);
}

void LinkedList::addToRear(string element)
{
	add(element);
}

void LinkedList::addAt(string element, int index) throw (string)
{
	if ((getCount() < index))
	{
		throw IND_RANG;
	}

	int ind = 0;
	Node *current = mFront->mNext;
	for (ind = 0; ind < index; ++ind)
	{
		current = current->mNext;
	}
	Node *nNode = new Node(element);
	nNode->mNext = current;
	nNode->mPrevious = current->mPrevious;
	nNode->mNext->mPrevious = nNode;
	nNode->mPrevious->mNext = nNode;
}

void LinkedList::addBefore(string elementToAdd, string elementToAddBefore) throw (string)
{
	if ((isPresent(elementToAddBefore) == false))
	{
		throw NOT_FOUND;
	}

	int index = find(elementToAddBefore);
	addAt(elementToAdd, index);
}

void LinkedList::addAfter(string elementToAdd, string elementToAddAfter) throw (string)
{
	if (isPresent(elementToAddAfter) == false)
	{
		throw NOT_FOUND;
	}

	int index = find(elementToAddAfter);
	addAt(elementToAdd, index + 1);
}

void LinkedList::remove(string element) throw (string)
{
	if (isPresent(element) == false)
	{
		throw NOT_FOUND;
	}
	removeAt(find(element));
}

void LinkedList::removeAt(int index) throw (string)
{
	if ((getCount() < index))
	{
		throw IND_RANG;
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

void LinkedList::removeFront() throw (string)
{
	if (getCount() == 0) {
		throw LIST_EMPTY;
	}
	removeAt(0);
}
 
void LinkedList::removeRear() throw (string)
{
	if (getCount() == 0) {
		throw LIST_EMPTY;
	}
	removeAt(getCount() - 1);
}

string LinkedList::getAt(int index) const throw (string)
{

	if (getCount() < index)
	{
		throw IND_RANG;
	}

	Node* current = mFront->mNext;
	for (int i = 0; i < index; ++i)
	{
		current = current->mNext;
	}
	return current->mData;
}

string LinkedList::getFront() const throw (string)
{
	if (getCount() == 0) {
		throw LIST_EMPTY;
	}
	return getAt(0);
}

string LinkedList::getRear() const throw (string)
{
	if (getCount() == 0) {
		throw LIST_EMPTY;
	}
	return getAt(getCount() - 1);
}

int LinkedList::getCount() const
{
	Node* current = mFront->mNext;
	int count = 0;
	while (current->mNext != NULL)
	{
		current = current->mNext;
		count++;
	}

	return count;
}

bool LinkedList::isEmpty() const
{
	if (getCount() == 0)
	{
		return true;
	}
	else {
		return false;
	}
}

bool LinkedList::isPresent(string element) const
{
	Node* current = mFront->mNext;

	while (current->mNext != NULL)
	{
		if (current->mData == element)
		{
			return true;
		}
		current = current->mNext;
	}
	return false;
}

vector<string> LinkedList::toVector(bool sorted) const
{
	Node* current = mFront->mNext;
	vector<string> s;
	for (int i = 0; i < getCount(); i++)
	{
		s.push_back(current->mData);
		current = current->mNext;
	}
	sort(s.begin(), s.end());
	return s;
}

LinkedList LinkedList::operator+(const LinkedList &other)
{
	LinkedList temp;
	Node *current = mFront->mNext;
	while (current->mNext)
	{
		temp.add(current->mData);
		current = current->mNext;
	}

	current = other.mFront->mNext;
	while (current->mNext)
	{
		temp.add(current->mData);
		current = current->mNext;
	}
	return temp;
}

LinkedList LinkedList::operator-(const LinkedList &other)
{
	LinkedList temp;
	Node *current = mFront->mNext;
	while (current->mNext)
	{
		temp.add(current->mData);
		current = current->mNext;
	}

	current = other.mFront->mNext;
	while (current->mNext)
	{
		temp.remove(current->mData);
		current = current->mNext;
	}
	return temp;
}

bool LinkedList::operator==(const LinkedList &other)
{
	Node* current = other.mFront->mNext;
	Node* current1 = mFront->mNext;
	int count = 0;
	while (count < getCount())
	{
		if (current1->mData != current->mData) {
			return false;
			current = current->mNext;
			current1 = current1->mNext;
			count++;
		}
	}
	return true;
}


//////////////////////////////////////////////////////////////
// Friends
//////////////////////////////////////////////////////////////

ostream& operator<<(ostream &os, const LinkedList &list)
{
	for (int i = 0; i < list.getCount(); i++)
	{
		os << list.getAt(i) << " ";
	}
	return os;
}

//////////////////////////////////////////////////////////////
// Private
//////////////////////////////////////////////////////////////

void LinkedList::init()
{
	mFront = new Node("Front");
	mRear = new Node("Rear");

	mFront->mNext = mRear;
	mRear->mPrevious = mFront;
}

void LinkedList::copyAll(const LinkedList &other)
{
	//mFront = other.mFront;
	//mRear = other.mRear;

	Node *current = other.mFront->mNext;
	while (current != other.mRear)
	{
		add(current->mData);
		current = current->mNext;
	}

}

void LinkedList::deleteAll()
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

int LinkedList::find(string s) const
{
	Node *current = mFront->mNext;
	int index = 0;
	while (current->mData != s) {
		++index;
		current = current->mNext;
	}
	return index;
}