#include <bits/stdc++.h>

using namespace std;

int inLimits(int i, int j, int n, int m)
{
	if ((i >= 0) && (i < n) && (j >= 0) && (j < m))
		return 1;
	return 0;
}
void dfs(int i, int j, int n, int m, vector<vector<int>> arr, vector<vector<int>> &visited)
{
	if (inLimits(i, j, n, m))
	{
		if ((!visited[i][j]) && (!arr[i][j]))
		{
			visited[i][j] = 1;
			dfs(i + 1, j, n, m, arr, visited);
			dfs(i - 1, j, n, m, arr, visited);
			dfs(i, j + 1, n, m, arr, visited);
			dfs(i, j - 1, n, m, arr, visited);
		}
	}
}

int main()
{
	int n, m;
	cin >> n;
	cin >> m;

	vector<vector<int>> arr;

	for (int i = 0; i < n; i++)
	{
		vector<int> ans;
		for (int j = 0; j < m; j++)
		{
			int res;
			cin >> res;
			ans.push_back(res);
		}
		arr.push_back(ans);
	}

	//write your code here
	int count = 0;
	vector<vector<int>> visited(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((!visited[i][j]) && (!arr[i][j]))
			{
				// visited[i][j] = 1;
				dfs(i, j, n, m, arr, visited);
				count++;
			}
		}
	}
	cout << count << endl;
}