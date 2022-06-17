#include <bits/stdc++.h>
using namespace std;

int jumpT(int i, int n, vector<int> &jumps, vector<int> &dp)
{
	// write your code here
	dp[n] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		int min = 100;
		for (int j = 1; j <= jumps[i]; j++)
		{
			if (min > dp[i + j] && min != 0)
				min = dp[i + j];
		}
		dp[i] = 1 + min;
	}
	// for (auto v : jumps)
	// 	cout << v << " ";
	// cout << endl;
	// for (auto v : dp)
	// 	cout << v << " ";
	// cout << endl;
	return dp[0];
}

int main()
{

	int n;
	cin >> n;

	vector<int> jumps(n);

	for (int i = 0; i < n; i++)
	{
		cin >> jumps[i];
	}

	vector<int> dp(n + 1, 0);

	int ans = jumpT(0, n, jumps, dp);

	if (ans < 30)
		cout << ans;
	else
		cout << "null";
}