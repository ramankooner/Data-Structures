#ifndef BST_H
#define BST_H

#include <vector>
using namespace std;


class BST
{
public:
	enum TraversalOrder { PREORDER, INORDER, POSTORDER };

	/*
	* Method Name:  BST
	*
	*    Makes an empty binary search tree
	*
	* Input only:
	*
	* Input & output:
	*
	* Output only:
	*
	* Returns:
	*     An empty Queue
	*
	* Side Effects:
	*
	* Throws:
	*
	*/
	BST();

	/*
	* Method Name:  add
	*
	*    Add an item to the binary search tree
	*
	* Input only:
	*	   data - string to add
	*	   key  - the specific key for each string
	* Input & Output:
	*
	* Output only:
	*
	* Returns:
	*
	* Side Effects:
	*
	* Throws:
	*
	*/
	void add(int key, string data);

	/*
	* Method Name:  isPresent
	*
	*    Tells whether or not the key is present
	*
	* Input only:
	*
	* Input & Output:
	*
	* Output only:
	*
	* Returns:
	*	   true - if key is present
	*      false - if key is not present
	*
	* Side Effects:
	*
	* Throws:
	*
	*/
	bool isPresent(int key) const;

	/*
	* Method Name:  getTraversal
	*
	*    sorts the data in one of the three traversal orders
	*
	* Input only:
	*
	* Input & Output:
	*
	* Output only:
	*
	* Returns:
	*		vector<string> - the vector with all the data
	*
	* Side Effects:
	*
	* Throws:
	*
	*/
	vector<string> getTraversal(TraversalOrder order) const;

	/*
	* Method Name:  evaluate
	*
	*    finds the value of the whole binary search tree
	*
	* Input only:
	*
	* Input & Output:
	*
	* Output only:
	*
	* Returns:
	*		double - result from solving the binary search tree
	*
	* Side Effects:
	*
	* Throws:
	*
	*/
	double evaluate();

	/*
	* Method Name:  evaluateAt
	*
	*    evaluates the binary search tree at a specific key
	*
	* Input only:
	*
	* Input & Output:
	*
	* Output only:
	*
	* Returns:
	*		double - result from solving the binary search tree at a specific key
	*
	* Side Effects:
	*
	* Throws:
	*
	*/
	double evaluateAt(int key);

private:

	class Node
	{
		friend class BST;
	public:
		Node(int key, string data);
		void add(int key, string data);
		void getTraversal(TraversalOrder order, vector<string>&keys, Node *root) const;
		bool isPresent(int key) const;
		double evaluate(Node *current);
		double evaluateAt(int key);

	private:
		int mKey;
		Node* mLeft;
		Node* mRight;
		string mData;
		double mValue;
	};

	//	Node *find(int key);  // Delete if you don't want it.
	Node *mRoot;		  // MUST use this

};

#endif
