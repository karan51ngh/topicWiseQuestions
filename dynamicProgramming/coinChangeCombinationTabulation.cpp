// given an array of coin denominations(with infinite supply for each coin) and a target
//find the number of ways u can pay the target using the available coins.(the number of combinations not permutations)
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
				// deb(i);
				// deb(j);
				// cout << endl;
			}
			else if (j == 0)
			{
				dp[i][j] = 1;
				// deb(i);
				// deb(j);
				// cout << endl;
				continue;
			}
			else if (arr[i] > j)
			{
				// deb(i);
				// deb(j);
				// cout << endl;
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				// deb(i);
				// deb(j);
				// cout << endl;
				dp[i][j] = dp[i][j - arr[i]] + dp[i - 1][j];
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
	arr.insert(arr.begin(), 0);
	cin >> t;
	sort(arr.begin(), arr.end());
	cout << f(arr, n, t) << endl;
}