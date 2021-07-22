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

int f(vi arr, int n, int start)
{
	deb(start);
	if (start == n)
	{
		return 0;
	}
	if (start > n)
	{
		return 10000000001;
	}
	else
	{
		int min = 10000000000;
		for (int i = 1; i <= arr[start]; i++)
		{
			int x = f(arr, n, start + i);
			if (x < min)
				min = x;
		}
		return min + 1;
	}
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

	cout << f(arr, n, 0) << endl;
}