#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int f(int n)
{
	vector<int> dp(n + 1);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	return dp[n];
}

int main()
{
	int n;
	cin >> n;
	cout << f(n) << endl;
}