#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
	int src;
	int nbr;
	Edge(int x, int y)
	{
		this->src = x;
		this->nbr = y;
	}
};

int f(vector<Edge> graph[], vector<int> &visited, int src)
{
	visited[src] = 1;
	int count = 1;
	for (auto v : graph[src])
	{
		if (!visited[v.nbr])
			count += f(graph, visited, v.nbr);
	}
	return count;
}

int main()
{
	int n;
	cin >> n;

	int k;
	cin >> k;

	vector<Edge> graph[n];
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(Edge(x, y));
		graph[y].push_back(Edge(y, x));
	}

	// write your code here
	vector<int> club_size;
	vector<int> visited(n, 0);
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			club_size.push_back(f(graph, visited, i));
		}
	}
	n = club_size.size();
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			res += club_size[i] * club_size[j];
		}
	}
	cout << res << endl;
}