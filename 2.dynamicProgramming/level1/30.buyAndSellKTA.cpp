#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void transactions(vector<int> arr, int n, int k)
{
	int dp[k + 1][n];
	for (int i = 0; i <= k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
				continue;
			}
			else
			{
				int maxx = 0;
				for (int l = 0; l < j; l++)
				{
					if (dp[i - 1][l] + arr[j] - arr[l] > maxx)
						maxx = dp[i - 1][l] + arr[j] - arr[l];
				}

				dp[i][j] = max(dp[i][j - 1], maxx);
			}
		}
	}
	// for (int i = 0; i <= k; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << dp[k][n - 1] << endl;
}

int main()
{

	int n;
	cin >> n;
	vector<int> arr(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int k;
	cin >> k;

	transactions(arr, n, k);

	return 0;
}