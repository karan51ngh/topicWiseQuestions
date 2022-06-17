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

int f(vector<vector<Edge>> graph, int vtces, queue<int> q, vector<int> &visited, vector<int> &level)
{
	int flag = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		if (!visited[x])
		{
			visited[x] = 1;
			flag *= -1;
			for (auto i : graph[x])
			{
				if ((level[i.nbr] == 0) || (level[i.nbr] == flag))
					level[i.nbr] = flag;
				else
					return 0;
				q.push(i.nbr);
			}
		}
	}

	return 1;
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
	vector<int> level(vtces, 0);

	for (int i = 0; i < vtces; i++)
	{

		queue<int> q;
		q.push(i);
		level[i] = 1;

		if (f(graph, vtces, q, visited, level) == 0)
		{
			cout << "false" << endl;
			return 0;
		}
	}
	cout << "true" << endl;
	return 0;
}