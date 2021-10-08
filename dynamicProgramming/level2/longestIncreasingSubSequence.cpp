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

int f(vi arr, int n)
{
	vi dp(n, 1);
	// dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				int x = dp[j] + 1;
				if (x > dp[i])
					dp[i] = x;
			}
		}
	}

	return *max_element(dp.begin(), dp.end());
}

void solved()
{
	int n;
	cin >> n;
	vi arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << f(arr, n) << endl;
}