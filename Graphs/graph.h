#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

class Graph
{
public:

	/*
	* Method Name:  Graph
	*
	*    Makes an empty graph
	*
	* Input only:
	*
	* Input & output:
	*
	* Output only:
	*
	* Returns:
	*     An empty graph
	*
	* Side Effects:
	*
	* Throws:
	*
	*/
	Graph();

	/*
	* Method Name:  addEdge
	*
	*    adds an edge to a node
	*
	* Input only:
	*
	*	from - Node we are adding from 
	*	to - Node we are adding to
	* Input & output:
	*
	* Output only:
	*
	* Returns:
	*     
	*
	* Side Effects:
	*
	* Throws:
	*
	*/
	void addEdge(int from, int to);

	/*
	* Method Name:  outputNodes
	*
	*    outputs the nodes vertices
	*
	* Input only:
	*
	* Input & output:
	*
	* Output only:
	*
	* Returns:
	*     
	*
	* Side Effects:
	*
	* Throws:
	*
	*/
	void outputNodes() const;

	/*
	* Method Name:  outputEdges
	*
	*    outputs the nodes edges
	*
	* Input only:
	*
	* Input & output:
	*
	* Output only:
	*
	* Returns:
	*    
	*
	* Side Effects:
	*
	* Throws:
	*
	*/
	void outputEdges() const;

	/*
	* Method Name:  DFS
	*
	*    does a depth for search from the specified node number
	*
	* Input only:
	*
	*	nodeNumberFrom - the number we will start the DFS from
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
	void DFS(int nodeNumberFrom);

private:

	class Node
	{

		friend Graph;

	public:
		Node(int nodeNumber);
		void addEdge(Node *to);
		void DFS();
		bool isAdjTo(int to);

	private:
		int mNodeNumber;
		vector<Node *> mAdjList;
		bool mVisited;
	};

	void markAllUnvisited();
	Node *find(int nodeNumber) const;
	vector<int> getNodeNumbers() const;

	vector<Node *> mNodes;

};


#endif
