// This problem can be done with GREEDY APPROACH(faster solution)
// implementing DP solution:
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
int f(vi arr, int l, int n, vi &DP)
{
	if (l >= n)
	{
		return 0;
	}
	else
	{
		if (DP[l] != -1)
			return DP[l];
		else
		{
			DP[l] = max(arr[l] + f(arr, l + 2, n, DP), f(arr, l + 1, n, DP));
			return DP[l];
		}
	}
}
void solved()
{
	int n;
	cin >> n;
	vi arr(n);
	vi DP(n, -1);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << f(arr, 0, n, DP) << endl;
	for (int i = 0; i < n; i++)
	{
		cout << DP[i] << " ";
	}
	cout << endl;
}