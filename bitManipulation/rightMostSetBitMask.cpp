// RMSB of x == x& 2's complement of x
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
void d2b(int n)
{
	int binaryNum[64];
	int i = 0;
	while (n > 0)
	{

		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}

	for (int j = i - 1; j >= 0; j--)
		cout << binaryNum[j];
}
int twoComp(int x)
{
	return ((~x) + 1);
}
void solved()
{
	int n;
	cin >> n;
	int x = (n & twoComp(n));
	d2b(x);
	cout << endl;
}