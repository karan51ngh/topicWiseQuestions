#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
	int src;
	int nbr;
	int wt;

	Edge(int src, int nbr, int wt)
	{
		this->src = src;
		this->nbr = nbr;
		this->wt = wt;
	}
};

void printAllPaths(int, int, vector<Edge>[], int, vector<int> &);

int main()
{
	int vtces;
	cin >> vtces;
	vector<Edge> graph[vtces]; // array of edges

	int edges;
	cin >> edges;
	for (int i = 0; i < edges; i++)
	{
		int v1;
		int v2;
		int wt;
		cin >> v1 >> v2 >> wt;
		graph[v1].push_back(Edge(v1, v2, wt));
		graph[v2].push_back(Edge(v2, v1, wt));
	}

	int src;
	cin >> src;
	int dest;
	cin >> dest;
	// write your code here
	vector<int> visited;
	for (int i = 0; i < vtces; i++)
	{
		visited.push_back(0);
	}
	//   cout << printAllPaths(src,dest,graph,vtces,visited)<<endl;
	if (printAllPaths(src, dest, graph, vtces, visited))
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

int printAllPaths(int src, int dest, vector<Edge> graph[], int vtcs, vector<int> &visited)
{
	if (src == dest)
		return 1;

	else
	{

		for (auto itr = graph[src].begin(); itr < graph[src].end(); itr++)
		{
			if (visited[itr->nbr] == 0)
			{
				visited[itr->nbr] = 1;
				if (printAllPaths(itr->nbr, dest, graph, vtcs, visited))
					return 1;
			}
		}

		return 0;
	}
}