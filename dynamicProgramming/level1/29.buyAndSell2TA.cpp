#include <iostream>
#include <bits/stdc++.h>
#include <climits>

using namespace std;

void transactions(int n, vector<int> arr)
{
	// write your code here
	vector<int> lr(n);
	int low = arr[0];
	int hp = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < low)
			low = arr[i];
		if (arr[i] - low > hp)
			hp = arr[i] - low;
		lr[i] = hp;
	}

	vector<int> rl(n);
	int high = arr[n - 1];
	hp = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] > high)
			high = arr[i];
		if (high - arr[i] > hp)
			hp = high - arr[i];
		rl[i] = hp;
	}

	int maxx = 0;
	for (int i = 0; i < n; i++)
	{
		if (lr[i] + rl[i] > maxx)
			maxx = lr[i] + rl[i];
	}

	// for (auto i : lr)
	// 	cout << i << " ";
	// cout << endl;

	// for (auto i : rl)
	// 	cout << i << " ";
	// cout << endl;

	cout << maxx << endl;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < arr.size(); i++)
	{
		cin >> arr[i];
	}

	transactions(n, arr);

	return 0;
}