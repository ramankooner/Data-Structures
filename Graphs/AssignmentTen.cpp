#include <iostream>
using namespace std;

#include "graph.h"

static void doDfs(Graph g, int from)
{
	cout << "Depth-First Search from Node " << from << " yields:" << endl;
	g.DFS(from);
	cout << endl;
}


void main()
{
	Graph g;


	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(1, 5);

	g.addEdge(3, 2);
	g.addEdge(3, 1);

	g.addEdge(5, 2);

	cout << endl;
	g.outputNodes();

	cout << endl;
	g.outputEdges();
	cout << endl;

	doDfs(g, 1);
	doDfs(g, 3);
	doDfs(g, 5);

	try
	{
		g.addEdge(9, 1);
	}
	catch (string s)
	{
		cout << "Adding edge (9,1) yields: " << s.c_str() << endl;
	}

	try
	{
		g.addEdge(3, 1);
	}
	catch (string s)
	{
		cout << "Adding edge (3,1) yields: " << s.c_str() << endl;
	}

	char a; cout << "Pause: "; cin >> a;
}