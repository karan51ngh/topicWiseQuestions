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
int f(vi arr, int n, int t, vector<vi> dp)
{
	if (t == 0)
		return 1;

	if (t < 0)
		return 0;

	else
	{
		if (dp[n][t] != -1)
			return dp[n][t];
		else
		{
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				int x = f(arr, n, t - arr[i], dp);
				sum += x;
			}
			dp[n][t] = sum;
			return sum;
		}
	}
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
	vector<vi> dp(n + 1, vector<int>(t + 1, -1));

	sort(arr.begin(), arr.end());
	cout << f(arr, n, t, dp) << endl;
}