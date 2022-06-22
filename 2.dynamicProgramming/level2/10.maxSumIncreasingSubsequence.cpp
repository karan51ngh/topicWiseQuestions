#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> dp(n);
	for (int i = 0; i < n; i++)
	{
		dp[i] = arr[i];
		for (int j = 0; j < i; j++)
		{
			if (arr[i] >= arr[j])
				dp[i] = max(dp[i], dp[j] + arr[i]);
		}
	}
	for (auto v : dp)
		cout << v << " ";
	cout << endl;
	// cout << *max_element(dp.begin(), dp.end()) << endl;
}
/*
15
35 35 97 25 97 54 46 22 26 86 13 48 99 63 38

*/