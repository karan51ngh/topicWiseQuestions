// https://www.youtube.com/watch?v=oBt53YbR9Kk&t=2319s
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long

int gridTraveler(int r, int c)
{
	int arr[r + 1][c + 1];
	for (int i = 0; i <= r; i++)
	{
		for (int j = 0; j <= c; j++)
		{
			if (i == 0 || j == 0)
			{
				arr[i][j] = 0;
				// cout << i << " " << j << " " << arr[i][j] << endl;
				continue;
			}
			if (i == 1 && j == 1)
			{
				arr[i][j] = 1;
				// cout << i << " " << j << " " << arr[i][j] << endl;
				continue;
			}
			else
			{
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
				// cout << i << " " << j << " " << arr[i][j] << endl;
			}
		}
	}
	return arr[r][c];
}

signed main()
{
	int r = 18, c = 18;
	// cin >> r >> c;
	cout << gridTraveler(r, c) << endl;
}