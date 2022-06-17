#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int f(int n, int m)
{
	vector<int> dp(n + 1);

	for (int i = 0; i <= n; i++)
	{
		if (i >= m)
			dp[i] = dp[i - m] + dp[i - 1];
		else
			dp[i] = 1;
	}
	// for (auto v : dp)
	// 	cout << v << " ";
	// cout << endl;
	return dp[n];
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << f(n, m) << endl;
}