/*
WEIGHTED DIRECTIONAL AND BIDIRECTIONAL GRAPH REPRESENTATION
*/

#include<iostream>
#include<unordered_map>
#include<list>
#include<cstring>
using namespace std;

class Graph
{
	private:
		unordered_map<string, list<pair<string, int>>> l;
		
	public:
		void addEdge(string x, string y, bool bidir = false, int wt = 0)
		{
			l[x].push_back(make_pair(y, wt));
			if(bidir)
			{
				l[y].push_back(make_pair(x, wt));
			}
		}
		
		void printAdjList()
		{
			// Iterate Over All The Keys in The Map
			for(auto p : l)
			{
				string city = p.first;
				list<pair<string, int>> nbrs = p.second;
				cout<<city<<"->";
				for(auto nbr : nbrs)
				{
					string dest = nbr.first;
					int dist = nbr.second;
					cout<<"("<<dest<<","<<dist<<")";
				}
				cout<<endl;
			}
		}	
};

int main()
{

	
	Graph g;
	g.addEdge("A", "B", true, 20);
	g.addEdge("B", "D");
	g.addEdge("A","C");
	g.addEdge("C","D");
	g.addEdge("A","D");

	g.printAdjList();
		
	
	return 0;
}


