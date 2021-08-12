// all elements appear twice, 1 element appears only once. find that element.
/*
	bits:
		b^1=~b
		b^0=b
	Decimal:
		x^x=0
		x^0=x
		x^y^z = x ^(y^z) = (x^y)^z = z^x^y ...

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
int f(vi arr, int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		t = t ^ arr[i];
	}
	return t;
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
	cout << f(arr, n) << endl;
}
