#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void f(int n, vector<int> arr)
{
	vector<int> bsp(n);
	vector<int> ssp(n);
	vector<int> csp(n);

	bsp[0] = -arr[0];
	ssp[0] = 0;
	csp[0] = 0;

	for (int i = 1; i < n; i++)
	{
		bsp[i] = max(bsp[i - 1], csp[i - 1] - arr[i]);
		ssp[i] = max(ssp[i - 1], arr[i] + bsp[i - 1]);
		csp[i] = max(csp[i - 1], ssp[i - 1]);
	}
	cout << max(ssp[n - 1], csp[n - 1]) << endl;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	f(n, arr);
}