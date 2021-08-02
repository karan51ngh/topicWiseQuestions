// count the number of binary strings with no consecutive 0's
// used binaryStringgenerator.cpp to generate strings and chk manually.
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
	if (n == 0)
	{
		return 1;
	}
	else
	{
		if (n != 1)
			return f2(n - 1) + f2(n - 2);
		else
			return 2;
	}
	return 0;
}
int f(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 2;
	else
		return f2(n - 1) + f2(n - 2);
}
void solved()
{
	int n;
	cin >> n;
	cout << f(n) << endl;
}