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
int f(int n)
{
	vi zero(n + 1);
	vi one(n + 1);
	zero[1] = 1;
	one[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		zero[i] = one[i - 1];
		one[i] = zero[i - 1] + one[i - 1];
	}
	return zero[n] + one[n];
}
void solved()
{
	int n;
	cin >> n;
	cout << f(n) << endl;
}