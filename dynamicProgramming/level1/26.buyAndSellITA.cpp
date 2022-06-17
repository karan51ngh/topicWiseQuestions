#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<int> arr)
{
	int summ = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i + 1] > arr[i])
			summ += arr[i + 1] - arr[i];
	}
	return summ;
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
	cout << f(n, arr) << endl;
}