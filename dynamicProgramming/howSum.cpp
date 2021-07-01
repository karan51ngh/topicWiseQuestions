// https://www.youtube.com/watch?v=oBt53YbR9Kk&t=5369s
#include <iostream>
#include <bits/stdc++.h>
#define int long
using namespace std;

vector<int> canSum(int N, int n, vector<int> arr)
{
	vector<vector<int>> sol; // list of all arrays
	vector<int> EMPTY;		 //NULL vector
	for (int i = 0; i <= N; i++)
	{
		sol.push_back(EMPTY);
	} //initializing sol

	for (int i = 0; i < N; i++)
	{
		if (sol[i] == EMPTY && i != 0)
		{
			continue;
		}
		for (int j = 0; j < n; j++)
		{
			int x;
			x = i + arr[j];
			if (sol[x] != EMPTY)
				continue;

			if (x <= N)
			{
				for (auto itr = sol[i].begin(); itr < sol[i].end(); itr++)
				{
					sol[x].push_back(*itr);
				}
				sol[x].push_back(arr[j]);
				// cout << endl<< "x is " << x << " i is " << i << " current state: ";
				// for (auto itr = sol[x].begin(); itr < sol[x].end(); itr++)
				// {
				// 	cout << *itr << " ";
				// }
				// cout << endl;
			}
			if (sol[N] != EMPTY)
			{
				return sol[N];
			}
		}
	}

	return EMPTY;
}

signed main()
{
	int N, n;
	cin >> N >> n;
	vector<int> arr;
	vector<int> sol;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		arr.push_back(t);
	}

	sol = canSum(N, n, arr);

	for (auto itr = sol.begin(); itr < sol.end(); itr++)
	{
		cout << *itr << " ";
	}
	cout << endl;
}