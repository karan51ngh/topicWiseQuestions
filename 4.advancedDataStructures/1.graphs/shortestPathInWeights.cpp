#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
	int src;
	int ndr;
	int wt;
	Edge(int src, int ndr, int wt)
	{
		this->src = src;
		this->ndr = ndr;
		this->wt = wt;
	}
};

int main()
{
	int vtces;
	cin >> vtces;
	vector<vector<Edge>> graph(vtces, vector<Edge>());
}