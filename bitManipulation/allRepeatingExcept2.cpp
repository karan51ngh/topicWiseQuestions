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
void f(vi arr, int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		t = t ^ arr[i];
	}
	int rsb = t & (-t);
	// deb(rsb);
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		if ((rsb & arr[i]) != 0)
		{
			// deb(x);
			// deb(arr[i]);
			x = x ^ arr[i];
		}
	}
	cout << x << endl;
	cout << (t ^ x) << endl;
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
	f(arr, n);
}