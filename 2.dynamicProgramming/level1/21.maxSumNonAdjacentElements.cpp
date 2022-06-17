#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int f(vector<int> arr, int n)
{
	vector<int> endsWithI(n);
	vector<int> doesntEndsWithI(n);

	endsWithI[0] = arr[0];
	doesntEndsWithI[0] = 0;

	for (int i = 1; i < n; i++)
	{
		endsWithI[i] = doesntEndsWithI[i - 1] + arr[i];
		doesntEndsWithI[i] = max(endsWithI[i - 1], doesntEndsWithI[i - 1]);
	}
	return max(doesntEndsWithI[n - 1], endsWithI[n - 1]);
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << f(arr, n) << endl;
}