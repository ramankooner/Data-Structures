#ifndef STACK_H
#define STACK_H

#include <string>
using namespace std;

/*
*
* stack.h
*
*
* This is the header file for the stack.h. In this header file,
* we create the methods we will be using in our stack. Our main 
* methods are the pop and push methods. These will be used to 
* delete data and add data to our linked list, which we declare
* as an object in the stack. The stack follows a LIFO pattern
* which stands for last in, first out. 
*
*
*/

#include "linked_list.h"

class Stack
{
public:

	/*
	* Method Name: Stack
	*
	*    This method will call the init method from our private data so we can
	*	 initialize an linked list. Our init will be blank since we are using 
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
	Stack();

	/*
	* Method Name: Stack
	*
	*	 This is the copy constructor which will take an instance of a stack
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
	Stack(const Stack &other);

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
	Stack operator=(const Stack &other);

	/*
	* Method Name: ~Stack
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
	~Stack();

	/*
	* Method Name: push
	*
	*	 This method will be used to add an element to the collection
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
	void push(string item);

	/*
	* Method Name: pop
	*
	*	 This method will be used to remove the element which has been
	*    most recently added to the collection
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
	* Throws:
	*	 LIST_EMPTY - throws this if we try to remove from an empty list
	*/
	void pop() throw(string);  // Throws if stack is empty

	
	/*
	* Method Name: getTop
	*
	*	 This method will return the string at the top of the stack, which will
	*    be the string which is most recently added
	*
	* Input Only:
	*	
	* Input & Output:
	*
	* Output Only:
	*
	* Returns:
	*    lists - this is the string that is most recently added to the stack
	* Side Effects:
	*
	* Throws:
	*	 LIST_EMPTY - throws this if we try to get the top from an empty list
	*/
	string getTop() const throw(string); // Throws if stack is empty

	
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
	*	  true - returns true if the list is empty
	*	  false - returns false if the list is not empty
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
	*	 &s - this is used so that whenever a stack is called, this function will be used
	* Output Only:
	*
	* Returns:
	*	 returns os so that the output will be showed in the main
	* Side Effects:
	*
	*/
	friend ostream &operator<<(ostream &os, const Stack &s);

private:
	void init();
	void copy(const Stack &other);
	void deleteAll();

	LinkedList mList;
};

#endif
