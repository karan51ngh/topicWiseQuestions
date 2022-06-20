#include <bits/stdc++.h>
using namespace std;

int f2(vector<vector<int>> dp, int i, int j)
{
	int n = dp.size();
	int m = dp[0].size();
	if (i >= 0 && i < n && j >= 0 && j < m)
		return dp[i][j];
	return 0;
}

int f(vector<vector<int>> arr, int n, int m)
{
	vector<vector<int>> dp(n, vector<int>(m));
	int maxx = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			if (arr[i][j] == 0)
				dp[i][j] = 0;
			else
			{
				dp[i][j] = 1 + min({f2(dp, i + 1, j), f2(dp, i, j + 1), f2(dp, i + 1, j + 1)});
				if (dp[i][j] > maxx)
					maxx = dp[i][j];
			}
		}
	}
	return maxx;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	cout << f(arr, n, m) << endl;
}