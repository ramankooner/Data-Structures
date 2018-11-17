#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <vector>
#include <string>
using namespace std;

/*
*
* linked_list.h
*
*
* This linkedlist header file will be used to create a linked list using vectors.
* We can then modify the linked list using methods that we create. This is a 
* doubly linked list so we will have an mFront, mPrevious, mData, mNext and 
* a mRear. We will use pointers to create the linked list.
*
*
*/

class LinkedList
{
public:

	/*
	* Method Name: LinkedList
	*
	*    This method will call the init method from our private data so we can
	*	 initialize an mFront and mRear and have them pointing to each other.
	*
	* Input Only:
	*
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*
	* Side Effects:
	*
	*/
	LinkedList();

	/*
	* Method Name: LinkedList
	*
	*    This method will create a vector because we will be taking strings from
	*	 a vector in the main function and creating a linked list from them
	*
	* Input Only:
	*
	* Input & Output:
	*	 This takes input and output because we use the & symbol and this 
	*	 creates a call by reference 
	* Output Only:
	*
	* Returns:
	*
	* Side Effects:
	*
	*/
	LinkedList(vector<string> &strings);  //dealing with a vector, need to write code for this
	
	/*
	* Method Name: LinkedList
	*
	*	 This is the copy constructor which will take an instance of a linked list
	*	 and create a copy of it
	*
	* Input Only:
	*
	* Input & Output:
	*	 This method uses input and output because we use the & symbol
	*	 which means call by reference
	* Output Only:
	*
	* Returns:
	*
	* Side Effects:
	*
	*/
	LinkedList(const LinkedList &other);

	/*
	* Method Name: operator=
	*
	*	 This method will be used for = operator. This will return *this after
	*	 we call the deleteAll and copyAll method
	*
	* Input Only:
	*
	* Input & Output:
	*	 This method uses input and output because we use the & symbol
	*	 which means call by reference
	* Output Only:
	*
	* Returns:
	*	 *this - returns the strings from the vector
	* Side Effects:
	*
	*/
	LinkedList operator=(const LinkedList &other);   //if i have one linked list and i wanna assign it to another one
	
	/*
	* Method Name: ~LinkedList
	*
	*	 This is the destructor method and it will be used to prevent memory
	*	 leak 
	*
	* Input Only:
	*
	* Input & Output:
	*	
	* Output Only:
	*
	* Returns:
	*	 
	* Side Effects:
	*
	*/
	~LinkedList(); //destructor

	/*
	* Method Name: add
	*
	*	 This method will be used to add nodes to the linked list
	*
	* Input Only:
	*	 string element - This will be the element that will be added
	* Input & Output:
	*	 
	* Output Only:
	*
	* Returns:
	*
	* Side Effects:
	*
	*/
	void add(string element);  //adds to the back

	/*
	* Method Name: addToFront
	*
	*	This method will be used to add a new node to the front of the linked
	*	list
	*
	* Input Only:
	*	 String element - This will be the element that will be added to the front
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*
	* Side Effects:
	*
	*/
	void addToFront(string element);  //makes the new thing im adding the new front
	
	/*
	* Method Name: addToRear
	*
	*	 This method will be used to add elements to the rear of the linked list
	*	 
	* Input Only:
	*	 String element - this will be the element that is added to the back
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*
	* Side Effects:
	*
	*/
	void addToRear(string element);  //makes the new thing add to the rear
	
	/*
	* Method Name: addAt
	*
	*	 This method will be used to add strings at a specific location in the
	*	 linked list
	*
	* Input Only:
	*	 string element - this is the new element that will be added to the linked list
	*	 int index - this is the index at which the new element will be added
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*
	* Side Effects:
	*
	*/
	void addAt(string element, int index); // Indices: 0, 1, ..., n-1
	
	/*
	* Method Name: addBefore
	*
	*	 This method will be used to add a element before a specific element in the linked list
	*
	* Input Only:
	*	 string elementToAdd - this will be the element that will be added
	*	 elementToAddBefore - This will be the element that the new element will be added before
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*
	* Side Effects:
	*
	*/
	void addBefore(string elementToAdd, string elementToAddBefore); //
	
	/*
	* Method Name: addAfter
	*
	*	 This method will be used to add a string after a specific element
	*
	* Input Only:
	*	 string elementToAdd - this will be the element that will be added to the linked list
	*	 string elementToAddAfter - this will be the element that the new element will be added after
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*
	* Side Effects:
	*
	*/
	void addAfter(string elementToAdd, string elementToAddAfter);

	/*
	* Method Name: remove
	*
	*	 This method will be used to remove an element 
	*
	* Input Only:
	*	 string element - this is the string element that will be removed
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*
	* Side Effects:
	*
	*/
	void remove(string element); //removes the element u wanna remove at a particular index
	
	/*
	* Method Name: removeAt
	*
	*	 This method will be used to remove an item at a specific index
	*
	* Input Only:
	*	 int index - this is the index at which the element will be removed
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*
	* Side Effects:
	*
	*/
	void removeAt(int index); // Indices: 0, 1, ..., n-1
	
	/*
	* Method Name: removeFront
	*
	*	This method will remove the front of the linked list
	*
	* Input Only:
	*	 
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*
	* Side Effects:
	*
	*/
	void removeFront();

	/*
	* Method Name: removeRear
	*
	*	This method will remove the rear of the linked list
	*
	* Input Only:
	*
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*
	* Side Effects:
	*
	*/
	void removeRear();

	/*
	* Method Name: getAt
	*
	*	This method will get the index for a specific element
	*
	* Input Only:
	*	 int index - the index of the specific element we want
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*	 Returns the current node pointing to the data
	* Side Effects:
	*
	*/
	string getAt(int index) const; // Indices: 0, 1, ..., n-1

	/*
	* Method Name: getFront
	*
	*	This method will get the string at the front of the linked list
	*
	* Input Only:
	*	 
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*	 returns the string at position 0 
	* Side Effects:
	*
	*/
	string getFront() const;

	/*
	* Method Name: getRear
	*
	*	This method will return the element at the end of the list
	*
	* Input Only:
	*
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*	 Returns the string at getCount - 1, which takes the size of the linked list 
	*	 and subtracts 1 by it to find the last value
	* Side Effects:
	*
	*/
	string getRear() const;

	/*
	* Method Name: getCount
	*
	*	This method will get the count of the linked list
	*
	* Input Only:
	*
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*	 Returns the count of the linked as an int 
	* Side Effects:
	*
	*/
	int getCount() const;

	/*
	* Method Name: isEmpty
	*
	*	This method will evaluate whether or not the list is empty as a bool
	*
	* Input Only:
	*
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*	 This method will return true if getCount = 0 and false if it doesnt equal 0
	* Side Effects:
	*
	*/
	bool isEmpty() const;

	/*
	* Method Name: isPresent
	*
	*	This method will evaluate and return a bool for whether or not a string is present
	*	in the linked list
	*
	* Input Only:
	*	string element - this is the element that we will look for in the list
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*	 returns true if the element is present and false if it is not present
	* Side Effects:
	*
	*/
	bool isPresent(string element) const;

	/*
	* Method Name: toVector
	*
	*	This mehtod will sort the vector and put the strings into alphabetical order
	*
	* Input Only:
	*
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*	 returns the vector after it has been sorted
	* Side Effects:
	*
	*/
	vector<string> toVector(bool sorted) const; //converts the linked list to a vector , need to look up "c++ sort vector"

	/*
	* Method Name: operator+
	*
	*	This method will be used to add linked lists
	*
	* Input Only:
	*	 
	* Input & Output:
	*	 This method uses a reference due to the use of the &
	* Output Only:
	*
	* Returns:
	*	 Returns the linked list after it has added the values
	* Side Effects:
	*
	*/
	LinkedList operator+(const LinkedList &other); //concantenates multiple lists
	
	/*
	* Method Name: operator-
	*
	*	This method will create the method for subtracting linked list
	*
	* Input Only:
	*	 
	* Input & Output:
	*	This method will have an input and output because of the use of the &
	* Output Only:
	*
	* Returns:
	*	Returns the list after it has subtracted the values
	* Side Effects:
	*
	*/
	LinkedList operator-(const LinkedList &other); //subtracts lists
	
	/*
	* Method Name: operator==
	*
	*	This method will return a bool for whether or not the linked lists equal each other
	*
	* Input Only:
	*	 
	* Input & Output:
	*	This uses input and output because of the & which is a call by reference
	* Output Only:
	*
	* Returns:
	*	 Returns true if the linked lists equal each other and false if they dont
	* Side Effects:
	*
	*/
	bool operator==(const LinkedList &other);

	/*
	* Method Name: operator<<
	*
	*	This method will used to print the appropriate output for our output
	*
	* Input Only:
	*
	* Input & Output:
	*	 &os - this is the what will be returned
	*	 &list - this is used so that whenever a list is called, this function will be used
	* Output Only:
	*
	* Returns:
	*	 returns os so that the output will be showed in the main
	* Side Effects:
	*
	*/
	friend ostream &operator<<(ostream &os, const LinkedList &list); //allows u to compare a class in a class

private:

	class Node
	{
		friend class LinkedList;

	private:
		inline Node(string data)
		{
			mPrevious = mNext = 0;
			mData = data;
		}

		string mData;
		Node *mPrevious;
		Node *mNext;
	};

	void init();
	void copyAll(const LinkedList &other);
	void deleteAll();

	int find(string s) const;

	Node *mFront;
	Node *mRear;

};
#endif
