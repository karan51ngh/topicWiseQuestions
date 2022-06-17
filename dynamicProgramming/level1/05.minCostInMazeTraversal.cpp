#include <iostream>
#include <vector>

using namespace std;

int minCost(int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
	dp[n - 1][m - 1] = arr[n - 1][m - 1];

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			if (i == n - 1 && j == m - 1)
				continue;
			else
			{
				if (i + 1 < n && j + 1 < m)
					dp[i][j] = arr[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
				if (i + 1 < n && j + 1 >= m)
					dp[i][j] = arr[i][j] + dp[i + 1][j];
				if (i + 1 >= n && j + 1 < m)
					dp[i][j] = arr[i][j] + dp[i][j + 1];
			}
		}
	}
	return dp[0][0];
}

int main()
{

	int n;
	int m;

	cin >> n >> m;

	vector<vector<int>> arr(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	vector<vector<int>> dp(n, vector<int>(m));

	cout << minCost(n, m, arr, dp);
}