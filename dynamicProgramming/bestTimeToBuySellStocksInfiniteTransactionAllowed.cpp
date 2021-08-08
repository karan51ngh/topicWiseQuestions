// cant have a transaction like BBSS
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
int f(vi arr, int n)
{
	vi mini;
	vi maxi;
	if (arr[1] > arr[0])
		mini.push_back(arr[0]);

	for (int i = 1; i <= n - 2; i++)
	{
		if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
		{
			// cout << "YOLO\n";
			maxi.push_back(arr[i]);
		}
		if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
		{
			// cout << "yolo\n";
			mini.push_back(arr[i]);
		}
	}
	if (arr[n - 1] > arr[n - 2])
	{
		maxi.push_back(arr[n - 1]);
	}
	int N = mini.end() - mini.begin();

	// deb(N);
	// for (int i = 0; i < N; i++)
	// {
	// 	cout << maxi[i] << " ";
	// }
	// cout << endl;
	// for (int i = 0; i < N; i++)
	// {
	// 	cout << mini[i] << " ";
	// }
	// cout << endl;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += maxi[i] - mini[i];
	}
	return sum;
}
void solved()
{
	int n;
	cin >> n;
	vi arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << f(arr, n) << endl;
}