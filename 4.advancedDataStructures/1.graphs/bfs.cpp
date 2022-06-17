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

void f(vector<vector<Edge>> graph, vector<int> visited, queue<int> q, queue<vector<int>> psf)
{

	while (!q.empty())
	{

		int x = q.front();
		vector<int> path = psf.front();
		q.pop();
		psf.pop();
		if (!visited[x])
		{
			visited[x] = 1;
			for (auto i : graph[x])
			{
				q.push(i.nbr);
				vector<int> temp = path;
				temp.push_back(i.nbr);
				psf.push(temp);
			}
			cout << x << "@";
			for (auto i : path)
				cout << i;
			cout << endl;
		}
	}
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

	int src;
	cin >> src;
	// write your code here
	vector<int> visited(vtces, 0);
	// visited[src] = 1;
	queue<int> q;
	q.push(src);
	queue<vector<int>> psf;
	vector<int> temp;
	temp.push_back(src);
	psf.push(temp);
	f(graph, visited, q, psf);

	return 0;
}