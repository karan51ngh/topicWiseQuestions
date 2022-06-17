#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void targetSumSubset(int n, vector<int> arr, int tar)
{
	int dp[n + 1][tar + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= tar; j++)
		{
			if (i == 0 && j != 0)
			{
				dp[i][j] = 0;
				continue;
			}
			if (j == 0)
			{
				dp[i][j] = 1;
				continue;
			}
			if (j - arr[i] >= 0)
			{
				dp[i][j] = max(dp[i - 1][j - arr[i]], dp[i - 1][j]);
				continue;
			}
			if (j - arr[i] < 0)
			{
				dp[i][j] = dp[i - 1][j];
				continue;
			}
		}
	}
	if (dp[n][tar])
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n + 1);
	arr[0] = 0;

	for (int i = 1; i < arr.size(); i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int tar;
	cin >> tar;
	targetSumSubset(n, arr, tar);
}