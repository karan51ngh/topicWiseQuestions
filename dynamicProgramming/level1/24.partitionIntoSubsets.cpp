#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int f(int n, int k)
{
	int dp[n + 1][k + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
				continue;
			}
			if (i == j)
			{
				dp[i][j] = 1;
				continue;
			}
			if (i < j)
			{
				dp[i][j] = 0;
				continue;
			}

			else
			{
				dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1];
			}
		}
	}
	// for (int i = 0; i <= n; i++)
	// {
	// 	for (int j = 0; j <= k; j++)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	return dp[n][k];
}
int main()
{
	int n, k;
	cin >> n >> k;
	cout << f(n, k) << endl;
}