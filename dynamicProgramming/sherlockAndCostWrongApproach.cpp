#include <iostream>
#include <bits/stdc++.h>
#define int long
#define deb(x) cout << #x << " is " << x << endl
using namespace std;

void solved();
int mod(int, int);
int cost(vector<int>, int);
signed main()
{
	int T;
	cin >> T;
	while (T--)
		solved();
}

void solved()
{
	int n;
	cin >> n;
	vector<int> B(n, 0);
	for (int i = 0; i < n; i++)
		cin >> B[i];

	vector<int> A1(n, 1);
	vector<int> A2(n, 1);

	for (int i = 0; i < n; i += 2)
	{
		A1[i] = B[i];
	}
	for (int i = 1; i < n; i += 2)
	{
		A2[i] = B[i];
	}

	for (auto itr = A1.begin(); itr < A1.end(); itr++)
	{
		cout << *itr << " ";
	}
	cout << endl;
	for (auto itr = A2.begin(); itr < A2.end(); itr++)
	{
		cout << *itr << " ";
	}
	cout << endl;

	int cost1 = cost(A1, n);
	int cost2 = cost(A2, n);
	deb(cost1);
	deb(cost2);
	cout << (cost1 >= cost2 ? cost1 : cost2) << endl;
}
int mod(int a, int b)
{
	return a >= b ? a - b : b - a;
}
int cost(vector<int> A, int n)
{
	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		sum += mod(A[i], A[i - 1]);
	}
	return sum;
}