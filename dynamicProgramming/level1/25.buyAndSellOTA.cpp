#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void f(int n, vector<int> arr)
{
	int low = arr[0];
	int curr = arr[0];
	int maxx = 0;
	for (int i = 0; i < n; i++)
	{
		curr = arr[i];
		if (curr < low)
			low = curr;
		if (curr - low > maxx)
			maxx = curr - low;
	}
	cout << maxx << endl;
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