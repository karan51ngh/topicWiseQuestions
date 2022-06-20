#include <bits/stdc++.h>
using namespace std;
int f2(vector<vector<int>> dp, int i, int j)
{
	int n = dp.size();
	int m = dp[0].size();

	if (i >= 0 && i < n && j >= 0 && j < m)
		return dp[i][j];
	return -1;
}
void f(vector<vector<int>> dp, int srci, int srcj, vector<int> psf, int n, int m, int &idx)
{
	if (srcj == m - 1)
	{
		cout << idx << " ";
		for (auto v : psf)
			cout << "d" << v << " ";
		cout << endl;
	}
	else
	{
		int x = max({f2(dp, srci - 1, srcj + 1), f2(dp, srci, srcj + 1), f2(dp, srci + 1, srcj + 1)});
		if (x == f2(dp, srci - 1, srcj + 1))
		{
			vector<int> psf_copy = psf;
			psf_copy.push_back(1);
			f(dp, srci - 1, srcj + 1, psf_copy, n, m, idx);
		}
		if (x == f2(dp, srci, srcj + 1))
		{
			vector<int> psf_copy = psf;
			psf_copy.push_back(2);
			f(dp, srci, srcj + 1, psf_copy, n, m, idx);
		}
		if (x == f2(dp, srci + 1, srcj + 1))
		{
			vector<int> psf_copy = psf;
			psf_copy.push_back(3);
			f(dp, srci + 1, srcj + 1, psf_copy, n, m, idx);
		}
	}
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
	for (int j = m - 1; j >= 0; j--)
	{
		for (int i = 0; i < n; i++)
		{
			if (j == m - 1)
			{
				dp[i][j] = arr[i][j];
			}
			else
			{
				dp[i][j] = arr[i][j] + max({f2(dp, i - 1, j + 1), f2(dp, i, j + 1), f2(dp, i + 1, j + 1)});
			}
		}
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << endl;
	// }
	int maxx = 0;
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		maxx = max(maxx, dp[i][0]);
		if (dp[i][0] == maxx)
			idx = i;
	}
	cout << maxx << endl;
	// cout << idx << " ";
	vector<int> psf;
	f(dp, idx, 0, psf, n, m, idx);
}