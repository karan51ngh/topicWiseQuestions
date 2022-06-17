#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
	int src;
	int nbr;
	Edge(int src, int nbr)
	{
		this->src = src;
		this->nbr = nbr;
	}
};
vector<int> dfs(vector<Edge> graph[], int vtces, vector<int> &visited, int src)
{
	vector<int> temp;
	temp.push_back(src);
	for (auto itr = graph[src].begin(); itr < graph[src].end(); itr++)
	{
		if (!visited[itr->nbr])
		{
			visited[itr->nbr] = 1;
			vector<int> temp2 = dfs(graph, vtces, visited, itr->nbr);
			for (auto i : temp2)
				temp.push_back(i);
		}
	}
	return temp;
}
vector<vector<int>> getConnectedComponents(vector<Edge> graph[], int vtces)
{
	vector<int> visited(vtces, 0);
	vector<vector<int>> result;
	for (int i = 0; i < vtces; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			vector<int> temp;
			temp = dfs(graph, vtces, visited, i);
			result.push_back(temp);
		}
	}
	return result;
}
int main()
{
	int n;
	cin >> n;

	int k;
	cin >> k;

	// write your code here
	vector<Edge> graph[n];
	for (int i = 0; i < k; i++)
	{
		int a;
		int b;
		cin >> a >> b;
		graph[a].push_back(Edge(a, b));
		graph[b].push_back(Edge(b, a));
	}

	vector<vector<int>> clubs;
	clubs = getConnectedComponents(graph, n);
	// for (auto v : clubs)
	// {
	// 	for (auto i : v)
	// 	{
	// 		cout << i << " ";
	// 	}
	// 	cout << endl;
	// }
	int count = 0;
	for (auto itr = clubs.begin(); itr < clubs.end(); itr++)
	{
		for (auto itr2 = itr + 1; itr2 < clubs.end(); itr2++)
		{
			// count += (*itr).size() * (*itr2).size();
			count += itr->size() * itr2->size();
		}
	}
	cout << count << endl;
}
