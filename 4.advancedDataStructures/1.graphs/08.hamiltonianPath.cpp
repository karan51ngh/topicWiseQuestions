#include <bits/stdc++.h>

using namespace std;

class Edge
{
public:
	int src = 0;
	int nbr = 0;
	int wt = 0;

	Edge(int src, int nbr, int wt)
	{
		this->src = src;
		this->nbr = nbr;
		this->wt = wt;
	}
};
bool f2(vector<Edge> graph[], int v1, int v2)
{
	for (auto v : graph[v1])
		if (v.nbr == v2)
			return true;
	return false;
}
void f(vector<Edge> graph[], vector<int> &visited, vector<int> &visited_chk, vector<int> psf, vector<vector<int>> &paths, int src)
{
	visited[src] = 1;
	psf.push_back(src);

	if (visited == visited_chk)
	{
		paths.push_back(psf);
	}
	else
	{
		for (auto v : graph[src])
		{
			if (!visited[v.nbr])
			{
				vector<int> psf_copy = psf;
				f(graph, visited, visited_chk, psf_copy, paths, v.nbr);
			}
		}
	}
	visited[src] = 0;
}

int main()
{
	int vtces;
	cin >> vtces;
	// vector<vector<Edge>> graph(vtces, vector<Edge>());
	vector<Edge> graph[vtces];

	int edges;
	cin >> edges;

	for (int i = 0; i < edges; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back(Edge(u, v, w));
		graph[v].push_back(Edge(v, u, w));
	}
	int src;
	cin >> src;
	vector<int> visited(vtces, 0);
	vector<int> visited_chk(vtces, 1);
	vector<vector<int>> paths;
	vector<int> psf;
	f(graph, visited, visited_chk, psf, paths, src);
	for (auto v : paths)
	{
		for (auto x : v)
			cout << x;
		if (f2(graph, v[0], v[v.size() - 1]))
			cout << "*";
		else
			cout << ".";
		cout << endl;
	}
}