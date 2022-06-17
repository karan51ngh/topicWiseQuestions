#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int f(int n)
{
	vector<int> endsWithZero(n + 1);
	vector<int> endsWithOne(n + 1);
	endsWithZero[1] = 1;
	endsWithOne[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		endsWithZero[i] = endsWithOne[i - 1];
		endsWithOne[i] = endsWithOne[i - 1] + endsWithZero[i - 1];
	}
	return endsWithOne[n] + endsWithZero[n];
}
int main()
{
	int n;
	cin >> n;
	cout << f(n) << endl;
}