#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Edge
{
public:
	int src = 0;
	int nbr = 0;

	Edge(int src, int nbr)
	{
		this->src = src;
		this->nbr = nbr;
	}
};

int bfsCheck(vector<vector<Edge>> graph, vector<int> &visited, vector<int> &parent, queue<int> q)
{
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (!visited[x])
		{
			visited[x] = 1;
			for (auto v : graph[x])
			{
				if (v.nbr != parent[x])
				{
					q.push(v.nbr);
					if (parent[v.nbr] == -1)
						parent[v.nbr] = x;
				}
			}
		}
		else
		{
			// for (auto v : visited)
			// 	cout << v;
			// cout << endl;
			return 1;
		}
	}
	// cout << "yo";
	// for (auto v : parent)
	// 	cout << v;
	// cout << endl;
	return 0;
}

int main()
{
	int vtces;
	cin >> vtces;
	vector<vector<Edge>> graph(vtces, vector<Edge>());

	int edges;
	cin >> edges;

	for (int i = 0; i < edges; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back(Edge(u, v));
		graph[v].push_back(Edge(v, u));
	}

	// write your code here
	vector<int> visited(vtces, 0);
	vector<int> parent(vtces, -1);

	for (int i = 0; i < vtces; i++)
	{
		if (!visited[i])
		{
			queue<int> q;
			q.push(i);
			if (bfsCheck(graph, visited, parent, q))
			{
				cout << "true" << endl;
				return 0;
			}
		}
	}
	cout << "false" << endl;
}