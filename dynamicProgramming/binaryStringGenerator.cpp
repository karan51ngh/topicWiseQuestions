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
void f(int n, string s)
{
	if (n == 0)
	{
		cout << s << endl;
		return;
	}
	else
	{
		string s1, s2;
		s1 = s + '0';
		s2 = s + '1';
		f(n - 1, s1);
		f(n - 1, s2);
	}
}
void solved()
{
	int n;
	cin >> n;
	cout << endl;
	f(n, "");
	cout << endl;
	cout << endl;
}