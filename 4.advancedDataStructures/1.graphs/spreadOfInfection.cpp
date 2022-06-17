#include <iostream>
#include <vector>
#include <queue>

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

int f(vector<vector<Edge>> graph, int vtces, int t, int src)
{
	vector<int> visited(vtces, 0);
	queue<int> q;
	q.push(src);
	vector<int> time(vtces, -1);
	time[src] = 0;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (!visited[x])
		{
			for (auto v : graph[x])
			{
				q.push(v.nbr);
				if (time[v.nbr] == -1)
					time[v.nbr] = time[x] + 1;
			}
			visited[x] = 1;
		}
	}
	// for (auto i : time)
	// 	cout << i << " ";
	// cout << endl;
	int count = 0;
	for (int i = 0; i < vtces; i++)
	{
		if (time[i] < t)
			count += 1;
	}
	return count;
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
	int src, t;
	cin >> src;
	cin >> t;

	//write your code here
	cout << f(graph, vtces, t, src) << endl;
	return 0;
}