#include <bits/stdc++.h>
using namespace std;

int f3(vector<vector<int>> &dp, int i, int j)
{
	int n = dp.size();
	int m = dp[0].size();

	if (i >= 0 && i < n && j >= 0 && j < m)
		return dp[i][j];
	return 1000000007;
}

void f2(vector<vector<int>> &dp, string psf, int srcx, int srcy, int desx, int desy, int n, int m)
{
	if (srcx == desx && srcy == desy)
	{
		cout << psf << endl;
	}
	else
	{
		if (f3(dp, srcx + 1, srcy) < f3(dp, srcx, srcy + 1))
		{
			psf.push_back('V');
			f2(dp, psf, srcx + 1, srcy, desx, desy, n, m);
		}
		if (f3(dp, srcx + 1, srcy) > f3(dp, srcx, srcy + 1))
		{
			psf.push_back('H');
			f2(dp, psf, srcx, srcy + 1, desx, desy, n, m);
		}
		if (f3(dp, srcx + 1, srcy) == f3(dp, srcx, srcy + 1))
		{
			string psf_copy1 = psf;
			string psf_copy2 = psf;

			psf_copy1.push_back('V');
			psf_copy2.push_back('H');
			f2(dp, psf_copy1, srcx + 1, srcy, desx, desy, n, m);
			f2(dp, psf_copy2, srcx, srcy + 1, desx, desy, n, m);
		}
	}
}

int f(vector<vector<int>> &dp, int i, int j)
{
	int n = dp.size();
	int m = dp[0].size();

	if (i >= 0 && i < n && j >= 0 && j < m)
		return dp[i][j];
	return 1000000007;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> arr(n, vector<int>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	vector<vector<int>> dp(n, vector<int>(m));

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			if (i == n - 1 && j == m - 1)
				dp[i][j] = arr[i][j];
			else
				dp[i][j] = arr[i][j] + min(f(dp, i + 1, j), f(dp, i, j + 1));
		}
	}
	cout << dp[0][0] << endl;
	f2(dp, "", 0, 0, n - 1, m - 1, n, m);
}