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

void f(int vtces, vector<Edge> graph[], int src, int dest, vector<vector<int>> &paths, vector<int> &psf, vector<int> visited)
{
	psf.push_back(src);
	if (src == dest)
	{
		paths.push_back(psf);
	}
	else
	{
		visited[src] = 1;
		for (auto v : graph[src])
		{
			if (visited[v.nbr] == 0)
			{
				vector<int> psf_copy = psf;
				f(vtces, graph, v.nbr, dest, paths, psf_copy, visited);
			}
		}
		visited[src] = 0;
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
	vector<vector<int>> paths;
	vector<int> psf;
	vector<int> visited(vtces, 0);
	f(vtces, graph, src, dest, paths, psf, visited);
	for (auto v : paths)
	{
		for (auto x : v)
			cout << x;
		cout << endl;
	}
}