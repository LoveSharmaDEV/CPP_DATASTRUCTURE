/*

A Graph is a Non-Linear Data Structure. It is basically a triplet of (EDGES, VERTICES, RELATIONS).

DIFFERENT WAYS OF REPRESENTING A GRAPH DATA-STRUCTURE:-

1. ADJACENCY MATRIX : Matrix of (V X V) dimension denoting edges between each vertices pair combination.
2. LIST OF EDGES AND VERTICES (EDGE LIST) : V = {0,1,2,3}, E = {(0,1), (0,2), (1,2), (2,3)}.
3. ADJACENCY LIST : Representing adjacent nodes.
*/

// GRAPH REPRESENTATION USING ADJACENCY LIST

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
        private:
 		int V;
 		list<int> *l;
 
 	public:
		Graph(int V)
		{	
			this->V = V;
			l = new list<int>[V]; // Dynamic memory Allocation
		}
		
		void addEdge(int x, int y)
		{
			l[x].push_back(y);
			l[y].push_back(x);
		}
		
		void printAdjList()
		{
			for(int i=0; i<V; i++)
			{
				cout<<" Vertex "<< i <<"->";
				for(int nbr: l[i])
				{
					cout<<nbr<<" "; 
				}
			}
			cout<<endl;
		}
};



int main()
{
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(2,3);
	g.addEdge(1,2);	
	g.printAdjList();	
	return 0;
}




