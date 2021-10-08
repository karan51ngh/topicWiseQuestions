//bitonic -> first increases then decreases
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
	vi lis(n, 1);
	vi lds(n, 1);

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				int x = lis[j] + 1;
				if (x > lis[i])
					lis[i] = x;
			}
		}
	}

	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (arr[i] > arr[j])
			{
				int x = lds[j] + 1;
				if (x > lds[i])
					lds[i] = x;
			}
		}
	}

	// for (int i = 0; i < n; i++)
	// 	cout << lis[i] << " ";
	// cout << endl;
	// for (int i = 0; i < n; i++)
	// 	cout << lds[i] << " ";
	// cout << endl;

	vi dp(n);
	for (int i = 0; i < n; i++)
		dp[i] = lis[i] + lds[i] - 1;

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