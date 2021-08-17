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
void f(int n)
{
	if (n == 1)
		cout << 1 << endl;
	else
	{
		f(n - 1);
		cout << n << endl;
	}
}
void solved()
{
	int n;
	cin >> n;
	f(n);
}