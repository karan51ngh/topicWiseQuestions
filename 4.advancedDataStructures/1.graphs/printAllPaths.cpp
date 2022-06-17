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
int notInPath(int x, vector<int> path)
{
	for (int i = 0; i < path.size(); i++)
	{
		if (path[i] == x)
			return 0;
	}
	return 1;
}
void f(vector<Edge> graph[], vector<int> path, int vtces, int src, int des)
{
	if (src == des)
	{
		for (auto itr = path.begin(); itr < path.end(); itr++)
			cout << *itr;
		cout << endl;
		return;
	}
	else
	{
		for (auto itr = graph[src].begin(); itr < graph[src].end(); itr++)
		{
			if (notInPath(itr->nbr, path))
			{
				vector<int> path2 = path;
				path2.push_back(itr->nbr);
				f(graph, path2, vtces, itr->nbr, des);
			}
		}
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

	int src;
	cin >> src;
	int dest;
	cin >> dest;
	// write your code here
	vector<int> path;
	path.push_back(src);
	f(graph, path, vtces, src, dest);
}