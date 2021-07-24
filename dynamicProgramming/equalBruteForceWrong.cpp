// https://www.hackerrank.com/challenges/equal/problem?isFullScreen=true
// doesnt work coz there is no proper termination condition
#include <iostream>
#include <bits/stdc++.h>
#include <limits>
#define int long
using namespace std;
void solved();
int equal(vector<int>, int, int);
bool check_equal(vector<int>, int);
int min(int, int, int);
vector<int> incrementExcept(vector<int>, int, int, int);
signed main()
{
	int T;
	cin >> T;
	while (T--)
	{
		solved();
	}
}
void solved()
{
	int n;
	cin >> n;
	vector<int> arr(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << equal(arr, n, 0);
	cout << endl;
}
bool check_equal(vector<int> arr, int n) //working
{
	int x = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != x)
			return 0;
	}

	return 1;
}
vector<int> incrementExcept(vector<int> arr, int index, int c, int n) //working
{
	for (int i = 0; i < n; i++)
	{
		if (i != index)
			arr[i] += c;
	}
	return arr;
}
int equal(vector<int> arr, int n, int cost)
{

	// choices -> 1,2,5
	// except 1 index
	vector<int> choices;
	choices.push_back(1);
	choices.push_back(2);
	choices.push_back(5);

	if (check_equal(arr, n))
	{
		return cost;
	}
	else
	{
		cout << "working\n";
		int min = INT_MAX;
		for (int i = 0; i < 3; i++) //choose by how much to increment
		{
			for (int j = 0; j < n; j++) //choce which person to ignore
			{
				vector<int> temp = incrementExcept(arr, j, choices[i], n);
				cout << " choices[i] is " << choices[i] << " i is " << i << " j is " << j << endl;
				int x = equal(temp, n, cost + 1);
				if (x < min)
					min = x;
			}
		}
		return min;
	}
}