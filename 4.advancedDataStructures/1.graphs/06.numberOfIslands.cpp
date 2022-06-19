#include <bits/stdc++.h>
using namespace std;

void f(int i, int j, int n, int m, vector<vector<int>> &visited, vector<vector<int>> &arr)
{
	if ((!(i >= 0 && i < n && j >= 0 && j < m) || visited[i][j] == 1))
		return;
	else
	{
		visited[i][j] = 1;
		f(i, j + 1, n, m, visited, arr);
		f(i + 1, j, n, m, visited, arr);
		f(i, j - 1, n, m, visited, arr);
		f(i - 1, j, n, m, visited, arr);
	}
}

int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	vector<vector<int>> arr;
	vector<vector<int>> visited(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		vector<int> ans;
		for (int j = 0; j < m; j++)
		{
			int res;
			cin >> res;
			if (res == 1)
				visited[i][j] = 1;
			ans.push_back(res);
		}
		arr.push_back(ans);
	}
	// write your code here

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j])
			{
				count++;
				f(i, j, n, m, visited, arr);
			}
		}
	}
	cout << count << endl;
}