#ifndef QUEUE_H
#define QUEUE_H

#include <string>
using namespace std;

#include "linked_list.h"

/*
*
* queue.h
*
* This is the header file for the queue. We will create the methods
* that we will be using in our queue in this file. The main methods 
* for our queue are the add and remove functions. Queue follows a 
* FIFO, which is a first in first out format. This means that we add 
* to the rear and we remove from the front. 
*
*/

class Queue
{
public:

	/*
	* Method Name: Queue
	*
	*    This method will call the init method from our private data so we can
	*	 initialize a linked list. Our init will be blank since we are using
	*    an object of a linked list.
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
	Queue();

	/*
	* Method Name: Queue
	*
	*	 This is the copy constructor which will take an instance of a queue
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
	Queue(const Queue &other);

	/*
	* Method Name: operator=
	*
	*	 This method will be used for the = operator. This will return *this after
	*	 we call the deleteAll, init() and copyAll methods
	*
	* Input Only:
	*
	* Input & Output:
	*	 This method uses input and output because we use the & symbol
	*	 which means call by reference
	* Output Only:
	*
	* Returns:
	*	 *this - returns the strings from the stack
	* Side Effects:
	*
	*/
	Queue operator=(const Queue &other);

	/*
	* Method Name: ~Queue
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
	~Queue();

	/*
	* Method Name: add
	*
	*	 This method will be used to add an element to the end of the collection
	*
	* Input Only:
	*	 item - this is the string which will be added
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*
	* Side Effects:
	*
	*/
	void add(string s);

	/*
	* Method Name: remove
	*
	*	 This method will be used to remove the element at the front
	*	 of the queue
	*
	* Input Only:
	*
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*	 s - s is the string that is at the front of the queue
	* Side Effects:
	*
	*/
	string remove();

	/*
	* Method Name: isEmpty
	*
	*	 This method will return a bool based on whether the list is empty
	*
	* Input Only:
	*
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*	  returns the isEmpty function from the linked list class which returns
	*	  true if the list is empty and false if it is not empty
	* Side Effects:
	*
	*/
	bool isEmpty() const;

	/*
	* Method Name: operator<<
	*
	*	This method will used to print the appropriate output
	*
	* Input Only:
	*
	* Input & Output:
	*	 &os - this is the what will be returned
	*	 &q - this is used so that whenever a stack is called, this function will be used
	* Output Only:
	*
	* Returns:
	*	 returns os so that the output will be showed in the main
	* Side Effects:
	*
	*/
	friend ostream &operator<<(ostream &os, const Queue &q);

private:
	void init();
	void copyAll(const Queue &other);
	void deleteAll();

	LinkedList mList;

};
#endif
