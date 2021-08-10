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
int f2(int n)
{
	//  2s complement
	return (~n) + 1;
}
int f(int n)
{
	int count = 0;
	while (n != 0)
	{
		int x = n & f2(n);
		count++;
		n -= x;
	}
	return count;
}
void solved()
{
	int n;
	cin >> n;
	cout << f(n) << endl;
}