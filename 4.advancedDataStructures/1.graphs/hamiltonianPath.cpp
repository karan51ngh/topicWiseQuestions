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
void printpath(vector<int> path)
{
	for (auto i : path)
		cout << i;
}
int checkCycle(vector<Edge> graph[], vector<int> path)
{
	int x = *(path.begin());
	int y = *(path.end() - 1);
	for (auto i : graph[x])
	{
		if (i.nbr == y)
			return 1;
	}
	return 0;
}
int checkVisited(vector<int> visited) //checks visited all 1
{
	for (auto i : visited)
	{
		if (i == 0)
			return 0;
	}
	return 1;
}
void f(vector<Edge> graph[], vector<int> visited, vector<int> psf, int src)
{
	if (checkVisited(visited))
	{
		printpath(psf);
		if (checkCycle(graph, psf))
			cout << "*" << endl;
		else
			cout << "." << endl;

		return;
	}
	for (auto i : graph[src])
	{
		if (!visited[i.nbr])
		{
			visited[i.nbr] = 1;
			psf.push_back(i.nbr);
			f(graph, visited, psf, i.nbr);
			psf.pop_back();
			visited[i.nbr] = 0;
		}
	}
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
	// for (int i = 0; i < vtces; i++)
	// {
	// 	cout << i << "  ";
	// 	for (auto j : graph[i])
	// 		cout << j.nbr << " ";
	// 	cout << endl;
	// }

	// write your codes here
	vector<int> visited(vtces, 0);
	visited[src] = 1;
	vector<int> psf;
	psf.push_back(src);
	f(graph, visited, psf, src);

	return 0;
}