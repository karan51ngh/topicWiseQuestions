#include <iostream>
#include <bits/stdc++.h>
#include <limits>
using namespace std;

int minn(vector<vector<int>> dp, int i, int j, int k)
{
	int minnn = INT_MAX;
	for (int z = 0; z < k; z++)
	{
		if (z == j)
			continue;
		if (dp[i][z] < minnn)
			minnn = dp[i][z];
	}

	return minnn;
}

int f(int n, int k, vector<vector<int>> arr)
{
	vector<vector<int>> dp(n, vector<int>(k));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (i == 0)
			{
				dp[i][j] = arr[i][j];
			}
			else
			{
				dp[i][j] = arr[i][j] + minn(dp, i - 1, j, k);
			}
		}
	}
	return minn(dp, n - 1, k, k);
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> arr(n, vector<int>(k));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << f(n, k, arr) << endl;
}