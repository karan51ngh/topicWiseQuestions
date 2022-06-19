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
bool hasPath(int n, int src, int des, vector<Edge> graph[], vector<int> &visited)
{
	visited[src] = 1;
	if (src == des)
		return true;
	else
	{
		bool dummy = false;
		for (auto v : graph[src])
		{
			if (visited[v.nbr] == 0)
			{
				dummy |= hasPath(n, v.nbr, des, graph, visited);
			}
		}
		return dummy;
	}
	return false;
}
int main()
{

	int n, e;
	cin >> n >> e;
	vector<Edge> graph[n];
	for (int i = 0; i < e; i++)
	{
		int src, nbr, wt;
		cin >> src >> nbr >> wt;
		graph[src].push_back(Edge(src, nbr, wt));
		graph[nbr].push_back(Edge(nbr, src, wt));
	}

	int src, des;
	cin >> src >> des;
	vector<int> visited(n, 0);
	if (hasPath(n, src, des, graph, visited) == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}