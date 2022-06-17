#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int f(int n, int k)
{
	vector<int> ii(n + 1);
	vector<int> ij(n + 1);

	ii[2] = k;
	ij[2] = k * (k - 1);
	for (int i = 3; i <= n; i++)
	{
		ii[i] = ij[i - 1];
		ij[i] = (ij[i - 1] + ii[i - 1]) * (k - 1);
	}
	return ii[n] + ij[n];
}
int main()
{
	int n, k;
	cin >> n >> k;

	cout << f(n, k) << endl;
}