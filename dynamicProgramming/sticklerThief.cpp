// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/?category[]=Dynamic%20Programming&category[]=Dynamic%20Programming&company[]=Amazon&company[]=Amazon&problemStatus=unsolved&difficulty[]=0&page=1&query=category[]Dynamic%20Programmingcompany[]AmazonproblemStatusunsolveddifficulty[]0page1company[]Amazoncategory[]Dynamic%20Programming
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

int findMax(int arr[], int n)
{
	if (n == 2)
	{
		return max(arr[1], arr[2]);
	}
	if (n == 1)
	{
		return arr[1];
	}
	if (n == 0)
	{
		return 0;
	}
	else
	{
		return max(arr[n] + findMax(arr, n - 2), arr[n - 1] + findMax(arr, n - 3));
	}
}

void solved()
{
	int n;
	cin >> n;
	int arr[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	arr[0] = 0;

	cout << findMax(arr, n) << endl;
}