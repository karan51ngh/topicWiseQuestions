/*
1. You are given a number n.
2. Print the number produced on setting its i-th bit.
3. Print the number produced on unsetting its j-th bit.
4. Print the number produced on toggling its k-th bit.
5. Also, Check if its m-th bit is on or off. Print 'true' if it is on, otherwise print 'false'.
*/
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
	int n, i, j, k, m;
	cin >> n >> i >> j >> k >> m;
	int maski = 1 << i;
	int maskj = 1 << j;
	maskj = ~maskj;
	int maskk = 1 << k;
	int maskm = 1 << m;

	cout << (n | maski) << endl;
	cout << (n & maskj) << endl;
	cout << (n ^ maskk) << endl;
	(n & maskm) == 0 ? cout << "false\n" : cout << "true\n";
}