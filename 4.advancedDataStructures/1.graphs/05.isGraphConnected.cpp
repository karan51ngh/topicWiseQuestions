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
void f(vector<Edge> graph[], vector<int> &visited, int src)
{
	visited[src] = 1;
	for (auto v : graph[src])
	{
		if (!visited[v.nbr])
			f(graph, visited, v.nbr);
	}
}
int main()
{
	int vtces;
	cin >> vtces;
	vector<Edge> graph[vtces];

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

	// write your code here
	vector<int> visited(vtces, 0);
	vector<int> visited_copy(vtces, 0);
	f(graph, visited, 0);
	if (visited == visited_copy)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}