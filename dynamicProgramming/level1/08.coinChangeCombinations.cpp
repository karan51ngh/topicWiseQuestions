#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int f(vector<int> curr, int n, int amt)
{
	int dp[n + 1][amt + 1];

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= amt; j++)
		{
			if (i == 0 && j != 0)
			{
				dp[i][j] = 0;
				continue;
			}
			if (j == 0)
			{
				dp[i][j] = 1;
				continue;
			}
			if (j - curr[i] >= 0)
			{
				dp[i][j] = dp[i][j - curr[i]] + dp[i - 1][j];
				continue;
			}
			if (j - curr[i] < 0)
			{
				dp[i][j] = dp[i - 1][j];
				continue;
			}
		}
	}
	return dp[n][amt];
}

int main()
{
	int n;
	cin >> n;
	vector<int> curr(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> curr[i];
	int amt;
	cin >> amt;
	cout << f(curr, n, amt) << endl;
}