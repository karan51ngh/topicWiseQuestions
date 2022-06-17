#include <bits/stdc++.h>

using namespace std;
int f(vector<vector<int>> &dp, int n, int m, int i, int j)
{
	if (i >= 0 && j >= 0 && i < n && j < m)
		return dp[i][j];
	else
		return -1;
}

int collectGold(int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
	for (int j = m - 1; j >= 0; j--)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			if (j == m - 1)
				dp[i][j] = arr[i][j];
			else
				dp[i][j] = arr[i][j] + max({f(dp, n, m, i - 1, j + 1), f(dp, n, m, i, j + 1), f(dp, n, m, i + 1, j + 1)});
		}
	}
	int maxx = 0;
	for (int i = 0; i < n; i++)
	{
		if (maxx < dp[i][0])
			maxx = dp[i][0];
	}
	return maxx;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> arr(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	vector<vector<int>> dp(n, vector<int>(m, 0));

	cout << collectGold(n, m, arr, dp);
}