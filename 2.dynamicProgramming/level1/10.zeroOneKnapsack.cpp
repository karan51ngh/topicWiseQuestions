#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void zeroOneKnapsack(int n, vector<pair<int, int>> arr, int cap)
{

	//  write your code here
	int dp[n + 1][cap + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= cap; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
				continue;
			}

			if (j - arr[i].first >= 0)
			{
				dp[i][j] = max(arr[i].second + dp[i - 1][j - arr[i].first], dp[i - 1][j]);
				continue;
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	// for (int i = 0; i <= n; i++)
	// {
	// 	for (int j = 0; j <= cap; j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << endl;
	// }
	cout << dp[n][cap] << endl;
}

int main()
{

	int n;
	cin >> n;

	vector<int> val(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> val[i];
	}

	vector<int> weight(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> weight[i];
	}
	int cap;
	cin >> cap;
	vector<pair<int, int>> arr;
	for (int i = 0; i <= n; i++)
	{
		arr.push_back(pair<int, int>(weight[i], val[i]));
	}
	sort(arr.begin(), arr.end());

	zeroOneKnapsack(n, arr, cap);
}