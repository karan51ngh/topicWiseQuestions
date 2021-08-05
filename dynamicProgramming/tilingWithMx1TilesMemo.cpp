// solved
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
int f(int n, int m, vi &dp)
{
	if (n == 0)
		return 1;
	if (n < 0)
		return 0;
	else
	{
		if (dp[n] != -1)
			return dp[n];
		else
		{
			dp[n] = f(n - 1, m, dp) + f(n - m, m, dp);
			return dp[n];
		}
	}
}
void solved()
{
	int m, n;
	cin >> n >> m;
	vi dp(n + 1, -1);
	cout << f(n, m, dp) << endl;
}