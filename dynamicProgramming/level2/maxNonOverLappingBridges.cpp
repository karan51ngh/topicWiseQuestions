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
	// Longest Increasing SubSequence
}
void solved()
{
	int n;
	cin >> n;
	vector<tuple<int, int>> list(n);
	for (int i = 0; i < n; i++)
	{
		tuple<int, int> temp;
		int x, y;
		cin >> x;
		cin >> y;
		temp = make_tuple(x, y);
		list[i] = temp;
	}
	sort(list.begin(), list.end());
	// for (int i = 0; i < n; i++)
	// {
	// 	cout << get<0>(list[i]) << " " << get<1>(list[i]) << endl;
	// }
	vi arr(n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = get<1>(list[i]);
	}

	cout << f(arr, n) << endl;
}
