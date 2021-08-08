//solved
// not a DP problem, just a foundation problem for similar problems that  involve DP.
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
int f(vi arr, int n)
{
	vi dp(n);
	dp[0] = 0;
	int min = arr[0];
	int max = dp[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];

		dp[i] = arr[i] - min;
		if (dp[i] > max)
			max = dp[i];
	}
	return max;
}
void solved()
{
	int n;
	cin >> n;
	vi arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << f(arr, n) << endl;
}