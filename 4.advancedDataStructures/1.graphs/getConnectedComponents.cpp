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

vector<int> dfs(vector<Edge> graph[], vector<int> &visited, int src)
{
	vector<int> temp;
	temp.push_back(src);
	for (auto itr = graph[src].begin(); itr < graph[src].end(); itr++)
	{
		if (!visited[itr->nbr])
		{
			visited[itr->nbr] = 1;
			vector<int> temp2 = dfs(graph, visited, itr->nbr);
			for (auto i = temp2.begin(); i < temp2.end(); i++)
			{
				temp.push_back(*i);
			}
		}
	}
	return temp;
}

vector<vector<int>> f(vector<Edge> graph[], int vtces, vector<int> &visited)
{
	vector<vector<int>> comps;
	for (int i = 0; i < vtces; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			comps.push_back(dfs(graph, visited, i));
		}
	}
	return comps;
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
	vector<int> visited(vtces, 0);

	// write your code here
	comps = f(graph, vtces, visited);
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