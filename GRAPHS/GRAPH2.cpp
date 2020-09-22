// GRAPH REPRESENTATION USING ADJACENCY MATRIX

#include<iostream>
#include<bits/stdc++.h>
#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"
#define V 9
using namespace std;


void addEdge(int graph[V][V], int u, int v)
{
	graph[u][v] = 1;
}

void AdjMatrix(int graph[V][V])
{
	cout<<"Adjacency Matrix Is:-->"<<endl;
	cout<<UNDERLINE<<" ";
	for(int i=0; i<V; i++)
	{
		cout<<"|"<<i<<"|";
	}
	cout<<CLOSEUNDERLINE<<endl;
	for(int i=0; i< V; i++)
	{ cout<<UNDERLINE<<i<<"";
		for(int j = 0; j<V; j++)
		{
			cout<< "|"<<UNDERLINE<< graph[i][j]<<"|";
		}
		cout<<CLOSEUNDERLINE<<endl;
	}
	
}

int main()
{ 	
	
	int graph[V][V] = {0};
	int option, v1, v2;
	
	
	do
	{
		cout<<"\n\nChoose The Option Number: "<<endl;
		cout<<"0. Break: "<<endl;
		cout<<"1. Add An Edge: "<<endl;
		cout<<"2. Print The Adjacency Matrix: "<<endl;
		cin>>option;
		
		switch(option)
		{
			case 0:
				break;
			case 1:
				cout<<"Enter The Edge: \n1. Enter Vertice 1: ";
				cin>>v1;
				cout<<"Enter Vertice 2: ";
				cin>>v2;
				cout<<endl;
				addEdge(graph , v1, v2);
				break;
			case 2:
				AdjMatrix(graph);
				break; 
			default: 
				cout<<"Enter operation number correctly "<<endl;
		}
		 
	}while(option != 0);
	
	return 0;
}
