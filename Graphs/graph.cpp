#include "graph.h"
#include <iostream>
#include <vector>
using namespace std;

static const string DIS_GRAPH = "Causes disconnected graph";
static const string ALR_ADJ = "Vertex is already adjacent";

// Class graph public methods
Graph::Graph()
{

}

void Graph::addEdge(int from, int to)
{
	if (mNodes.size() == 0)
	{
		Node *nodeFrom = new Node(from);
		Node *nodeTo = new Node(to);
		mNodes.push_back(nodeFrom);
		mNodes.push_back(nodeTo);
		nodeFrom->addEdge(nodeTo);
	}

	else
	{
		Node *nodeFrom = find(from);
		Node *nodeTo = find(to);

		if (nodeFrom == 0)
		{
			throw DIS_GRAPH;
		}

		else
		{
			if (nodeTo == 0)
			{
				nodeTo = new Node(to);
				nodeFrom->addEdge(nodeTo);
				mNodes.push_back(nodeTo);
			}
			else
			{
				nodeFrom->addEdge(nodeTo);
			}
		}
	}
}

void Graph::outputNodes() const
{
	cout << "Vertices: ";
	for (int i = 0; i < mNodes.size(); ++i)
	{
		cout << mNodes.at(i)->mNodeNumber << " ";
	}
	cout << endl;
}

void Graph::outputEdges() const
{
	cout << "Edges: " << endl;
	for (int i = 0; i < mNodes.size(); ++i)
	{
		for (int j = 0; j < mNodes.at(i)->mAdjList.size(); ++j)
		{
			cout << "(" << mNodes.at(i)->mNodeNumber << "," << mNodes.at(i)->mAdjList.at(j)->mNodeNumber << ") ";
		}
		cout << endl;
	}
}

void Graph::DFS(int nodeNumberFrom)
{
	find(nodeNumberFrom)->DFS();
	markAllUnvisited();
	cout << endl;
}

// Class Node public methods
Graph::Node::Node(int nodeNumber)
{
	mNodeNumber = nodeNumber;
	mVisited = false;
}

void Graph::Node::addEdge(Node * to)
{
	for (int i = 0; i < mAdjList.size(); ++i)
	{
		if (mAdjList.at(i)->mNodeNumber == to->mNodeNumber)
		{
			throw ALR_ADJ;
		}
	}
	mAdjList.push_back(to);
}

void Graph::Node::DFS()
{
	if (mVisited != true)
	{
		cout << mNodeNumber << " ";
		mVisited = true;

		if (mAdjList.empty() == 0)
		{
			for (int i = 0; i < mAdjList.size(); ++i)
			{
				mAdjList.at(i)->DFS();
				mVisited = true;
			}
		}
	}
}

bool Graph::Node::isAdjTo(int to)
{
	for (int i = 0; i < mAdjList.size(); ++i)
	{
		if (mAdjList.at(i)->mNodeNumber == to)
		{
			return true;
		}
	}
	return false;
}

// Private Methods
void Graph::markAllUnvisited()
{
	for (int i = 0; i < mNodes.size(); ++i)
	{
		mNodes.at(i)->mVisited = false;
	}
}

Graph::Node * Graph::find(int nodeNumber) const
{
	for (int i = 0; i < mNodes.size(); ++i)
	{
		if (mNodes.at(i)->mNodeNumber == nodeNumber)
		{
			return mNodes.at(i);
		}
	}
	return 0;
}

vector<int> Graph::getNodeNumbers() const
{
	return vector<int>();
}