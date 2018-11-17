#include <iostream>
#include <string>
using namespace std;

#include "bst.h"

static void output(string text, vector<string> strings)
{
	cout << endl << text << endl;
	for (unsigned int ii = 0; ii < strings.size(); ++ii) cout << " " << strings.at(ii) << " ";
	cout << endl;

}
void main()
{
	BST *bst = new BST();
	bst->add(20, "*");
	bst->add(15, "-");
	bst->add(6, "+");
	bst->add(30, "/");
	bst->add(8, "2");
	bst->add(2, "4");
	bst->add(25, "14");
	bst->add(36, "7");
	bst->add(18, "3");
	
	cout << ((bst->isPresent(20)) ? "20 - Yes" : "20 - No") << endl;
	cout << ((bst->isPresent(8)) ? "8 - Yes" : "8 - No") << endl;
	cout << ((bst->isPresent(200)) ? "200 - Yes" : "200 - No") << endl;

	vector<string> keys = bst->getTraversal(BST::TraversalOrder::PREORDER);
	output("PreOrder", keys);

	keys = bst->getTraversal(BST::TraversalOrder::INORDER);
	output("InOrder", keys);

	keys = bst->getTraversal(BST::TraversalOrder::POSTORDER);
	output("PostOrder", keys);
	cout << endl;

	cout << "Value of tree is: " << bst->evaluate() << endl;;
	cout << "Value of subtree at key 20 is: " << bst->evaluateAt(20) << endl;
	cout << "Value of subtree at key 15 is: " << bst->evaluateAt(15) << endl;
	cout << "Value of subtree at key 30 is: " << bst->evaluateAt(30) << endl;
	cout << "Value of subtree at key 36 is: " << bst->evaluateAt(36) << endl;


	

	cout << "Pause: "; char a; cin >> a;

}