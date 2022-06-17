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
void dfs(vector<Edge> graph[], int src, vector<int> &visited)
{
	visited[src] = 1;
	for (auto itr = graph[src].begin(); itr < graph[src].end(); itr++)
	{
		if (!visited[itr->nbr])
		{
			visited[itr->nbr] = 1;
			dfs(graph, itr->nbr, visited);
		}
	}
}
int f(vector<Edge> graph[], int vtces, vector<int> &visited)
{
	vector<int> temp(vtces, 1);
	dfs(graph, 0, visited);
	return temp == visited;
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
	if (f(graph, vtces, visited))
		cout << "true" << endl;
	else
		cout << "false" << endl;
}