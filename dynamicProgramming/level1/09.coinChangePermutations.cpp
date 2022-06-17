#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int f2(int n, int i, vector<int> dp)
{
	if (i >= 0 && i <= n)
		return dp[i];
	else
		return 0;
}

int f(vector<int> curr, int n, int amt)
{
	vector<int> dp(amt + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= amt; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			// sum += dp[i - curr[j]];
			sum += f2(amt, i - curr[j], dp);
		}
		dp[i] = sum;
	}
	return dp[amt];
}

int main()
{
	int n;
	cin >> n;
	vector<int> curr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> curr[i];
	}
	int amt;
	cin >> amt;
	cout << f(curr, n, amt) << endl;
}