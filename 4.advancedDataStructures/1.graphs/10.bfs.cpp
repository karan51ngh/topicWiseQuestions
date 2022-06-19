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
void f(vector<Edge> graph[], int vtces, int src)
{
	queue<int> q;
	queue<vector<int>> paths;
	vector<int> path;
	path.push_back(src);
	paths.push(path);
	q.push(src);
	vector<int> visited(vtces, 0);

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		path = paths.front();
		paths.pop();
		if (!visited[x])
		{
			visited[x] = 1;

			cout << x << "@";
			for (auto v : path)
				cout << v;
			cout << endl;

			for (auto v : graph[x])
			{

				q.push(v.nbr);
				vector<int> path_copy = path;
				path_copy.push_back(v.nbr);
				paths.push(path_copy);
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
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(Edge(u, v));
		graph[v].push_back(Edge(v, u));
	}

	int src;
	cin >> src;
	// write your code here
	f(graph, vtces, src);
	return 0;
}