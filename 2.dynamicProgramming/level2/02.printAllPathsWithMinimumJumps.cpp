#include <bits/stdc++.h>
using namespace std;

void f(vector<int> arr, vector<int> dp, vector<int> psf, int src, int des)
{
	psf.push_back(src);
	if (src == des)
	{
		// display path
		for (int i = 0; i < psf.size() - 1; i++)
			cout << psf[i] << " -> ";
		cout << psf[psf.size() - 1] << " ." << endl;
	}
	else
	{

		for (int i = 1; i <= arr[src]; i++)
		{
			if (src + i < arr.size())
			{
				if (dp[src + i] == dp[src] - 1)
				{
					f(arr, dp, psf, src + i, des);
				}
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> dp(n);
	dp[n - 1] = 0;

	for (int i = n - 2; i >= 0; i--)
	{
		int minn = 1001;
		for (int j = 1; j <= arr[i]; j++)
		{
			minn = min(dp[i + j], minn);
		}
		dp[i] = minn + 1;
	}
	cout << dp[0] << endl;

	// traceback
	int src = 0;
	int des = n - 1;
	vector<int> psf;
	f(arr, dp, psf, src, des);
}