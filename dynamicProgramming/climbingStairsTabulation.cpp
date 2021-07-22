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
void solved()
{
	int n;
	cin >> n;
	vi arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	vi dp(n + 1, 100000000);
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= arr[i]; j++)
		{
			int x = i + j; //new step

			if (x <= n)
				if (dp[i] + 1 < dp[x])
					dp[x] = dp[i] + 1;
		}
	}
	if (dp[n] >= 100000000)
	{
		cout << "not possible\n";
		return;
	}
	cout << dp[n] << endl;
}