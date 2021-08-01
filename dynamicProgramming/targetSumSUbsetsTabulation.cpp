// calculate the number of subsets of a given array that will get u a target sum.
// used tabulation approach
#include <iostream>
#include <bits/stdc++.h>
#define int long
#define vi vector<int>
#define deb(x) cout << #x << " is " << x << endl
using namespace std;

void solved();

signed main()
{
	int T = 1;
	// cin >> T;
	while (T--)
		solved();
}
int f(vi arr, int n, int t)
{
	int dp[n + 1][t + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= t; j++)
		{
			if (i == 0 && j != 0)
			{
				dp[i][j] = 0;
				continue;
			}
			else if (j == 0)
			{
				dp[i][j] = 1;
				continue;
			}
			else if (arr[i] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j - arr[i]] + dp[i - 1][j];
			}
		}
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= t; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	return dp[n][t];
}
void solved()
{
	int n, t;
	cin >> n;
	vi arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> t;
	arr.insert(arr.begin(), 0);
	sort(arr.begin(), arr.end());
	for (int i = 0; i <= n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << f(arr, n, t) << endl;
}