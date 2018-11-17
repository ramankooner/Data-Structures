#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#include "bst.h"

BST::BST()
{
	// Returns empty BST
}

void BST::add(int key, string data)
{
	if (mRoot == NULL) mRoot = new Node(key, data);
	else mRoot->add(key, data);
}

bool BST::isPresent(int key) const
{
	if (mRoot == NULL) return false;
	else return mRoot->isPresent(key);
}

vector<string> BST::getTraversal(TraversalOrder order) const
{
	vector<string> traversalType;
	if (mRoot == NULL) return traversalType;
	else mRoot->getTraversal(order, traversalType, mRoot);
	return traversalType;
}

double BST::evaluate()
{
	if (mRoot == NULL) return 0.0;
	else return mRoot->evaluate(mRoot);
}

double BST::evaluateAt(int key)
{
	if (mRoot == NULL) return 0.0;
	else return mRoot->evaluateAt(key);
}

BST::Node::Node(int key, string data)
{
	mData = data;
	mValue = 0;
	mLeft = 0;
	mRight = 0;
	mKey = key;
}

void BST::Node::add(int key, string data)
{
	if (key < mKey)
	{
		if (mLeft == 0)
		{
			mLeft = new Node(key, data);
			return;
		}
		else
		{
			mLeft->add(key, data);
		}
	}
	else
	{
		if (mRight == 0)
		{
			mRight = new Node(key, data);
			return;
		}
		else
		{
			mRight->add(key, data);
		}
	}
}

void BST::Node::getTraversal(TraversalOrder order, vector<string>&keys, Node *root) const
{
	switch (order)
	{
	case BST::PREORDER:
		if (root == NULL) return;
		keys.push_back(root->mData);
		getTraversal(order, keys, root->mLeft);
		getTraversal(order, keys, root->mRight);
		break;
	case BST::INORDER:
		if (root == NULL) return;
		getTraversal(order, keys, root->mLeft);
		keys.push_back(root->mData);
		getTraversal(order, keys, root->mRight);
		break;
	case BST::POSTORDER:
		if (root == NULL) return;
		getTraversal(order, keys, root->mLeft);
		getTraversal(order, keys, root->mRight);
		keys.push_back(root->mData);
		break;
	default:
		if (root == NULL) return;
		break;
	}
}

bool BST::Node::isPresent(int key) const
{
	if (key == this->mKey)
	{
		return true;
	}
	else if (key < this->mKey)
	{
		if (mLeft == NULL)
		{
			return false;
		}
		else
		{
			return mLeft->isPresent(key);
		}
	}
	else if (key > this->mKey)
	{
		if (mRight == NULL)
		{
			return false;
		}
		else
		{
			return mRight->isPresent(key);
		}
	}
	else
	{
		return false;
	}
}

double BST::Node::evaluate(Node *current)
{
	if (current == NULL)
	{
		return 0;
	}
	else if (current->mData == "+")
	{
		return mLeft->evaluate(current->mLeft) + mRight->evaluate(current->mRight);
	}
	else if (current->mData == "-")
	{
		return mLeft->evaluate(current->mLeft) - mRight->evaluate(current->mRight);
	}
	else if (current->mData == "*")
	{
		return mLeft->evaluate(current->mLeft) * mRight->evaluate(current->mRight);
	}
	else if (current->mData == "/")
	{
		return mLeft->evaluate(current->mLeft) / mRight->evaluate(current->mRight);
	}
	else
	{
		return stod(current->mData);
	}
}

double BST::Node::evaluateAt(int key)
{
	if (key == this->mKey)
	{
		return evaluate(this);
	}
	else if (key < this->mKey)
	{
		if (mLeft == NULL)
		{
			return false;
		}
		else
		{
			return mLeft->evaluateAt(key);
		}
	}
	else if (key > this->mKey)
	{
		if (mRight == NULL)
		{
			return false;
		}
		else
		{
			return mRight->evaluateAt(key);
		}
	}
	else
	{
		return false;
	}
}
