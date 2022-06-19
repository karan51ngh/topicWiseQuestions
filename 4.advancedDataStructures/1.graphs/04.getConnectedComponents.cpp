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
void f(vector<Edge> graph[], vector<int> &visited, vector<int> &psf, int src)
{
	visited[src] = 1;
	psf.push_back(src);
	for (auto v : graph[src])
	{
		if (!visited[v.nbr])
		{
			f(graph, visited, psf, v.nbr);
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

	vector<vector<int>> comps;

	// write your code here
	vector<int> visited(vtces, 0);
	for (int i = 0; i < vtces; i++)
	{
		if (visited[i] == 0)
		{
			vector<int> psf;
			f(graph, visited, psf, i);
			comps.push_back(psf);
		}
	}

	cout << "[";
	for (int i = 0; i < comps.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < comps[i].size(); j++)
		{
			if (j != comps[i].size() - 1)
				cout << comps[i][j] << ", ";
			else
				cout << comps[i][j];
		}
		cout << "]";
		if (i != comps.size() - 1)
			cout << ", ";
	}
	cout << "]";
}