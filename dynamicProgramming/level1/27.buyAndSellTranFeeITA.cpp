#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void f(int n, vector<int> arr, int k)
{
	vector<int> bsp(n);
	vector<int> ssp(n);

	bsp[0] = -arr[0];
	ssp[0] = 0;
	for (int i = 1; i < n; i++)
	{
		bsp[i] = max(bsp[i - 1], ssp[i - 1] - arr[i]);
		ssp[i] = max(ssp[i - 1], arr[i] + bsp[i - 1] - k);
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	cout << bsp[i] << "   " << ssp[i] << endl;
	// }
	cout << ssp[n - 1] << endl;
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
	int k;
	cin >> k;
	f(n, arr, k);
}