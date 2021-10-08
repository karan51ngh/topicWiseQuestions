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
	for (int i = 0; i < n; i++)
		dp[i] = arr[i];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				int x = arr[i] + dp[j];
				if (x > dp[i])
					dp[i] = x;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << dp[i] << " ";
	cout << endl;
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