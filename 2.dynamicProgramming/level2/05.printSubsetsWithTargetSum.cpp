#include <bits/stdc++.h>
using namespace std;

// void f(vector<vector<int>> &dp, int n, int tar, vector<int> psf, vector<int> &arr, int srci, int srcj)
// {
// 	if (!(srci >= 0 && srci <= n && srcj >= 0 && srcj <= tar))
// 		return;
// 	if (srci == 0 && srcj == 0)
// 	{
// 		for (int i = psf.size() - 1; i >= 0; i--)
// 			cout << psf[i] - 1 << " ";
// 		cout << endl;
// 	}
// 	else
// 	{
// 		if (dp[srci][srcj] == 1)
// 		{

// 			f(dp, n, tar, psf, arr, srci - 1, srcj);
// 			psf.push_back(srci);
// 			f(dp, n, tar, psf, arr, srci - 1, srcj - arr[srci - 1]);
// 		}
// 		else
// 			return;
// 	}
// }

void f(vector<vector<int>> &dp, int n, int tar, vector<int> psf, vector<int> &arr, int srci, int srcj)
{
	queue<int> qi;
	queue<int> qj;
	queue<vector<int>> paths;

	qi.push(n);
	qj.push(tar);
	vector<int> psf;
	paths.push(psf);

	vector<vector<int>> sol;

	while (!paths.empty())
	{
		int srci = qi.front();
		int srcj = qj.front();
		psf = paths.front();

		qi.pop();
		qj.pop();
		paths.pop();

		if (dp[srci][srcj] == 1)
		{
			if (!(srci >= 0 && srci <= n && srcj >= 0 && srcj <= tar))
				continue;
			if (!(srci == 0 && srcj == 0))
			{
				vector<int> psf_copy = psf;
				qi.push(srci - 1);
				qj.push(srcj - arr[srci - 1]);
				psf.push_back(srci);
				paths.push(psf);

				qi.push(srci - 1);
				qj.push(srcj);
				paths.push(psf_copy);
			}
		}
		else
			continue;
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int tar;
	cin >> tar;

	vector<vector<int>> dp(n + 1, vector<int>(tar + 1));

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= tar; j++)
		{
			if (i == 0 && j != 0)
				dp[i][j] = 0;
			else if (j == 0)
				dp[i][j] = 1;
			else if (j - arr[i - 1] >= 0)
				dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j];
		}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= tar; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
	if (dp[n][tar])
	{
		cout << "true" << endl;
		vector<int> psf;
		f(dp, n, tar, psf, arr, n, tar);
	}
	else
		cout << "fasle" << endl;
}

// 0	// 1 0 0 0 0 0 0 0 0 0 0
// 4	// 1 0 0 0 1 0 0 0 0 0 0
// 2	// 1 0 1 0 1 0 1 0 0 0 0
// 7	// 1 0 1 0 1 0 1 1 0 1 0
// 1	// 1 1 1 1 1 1 1 1 1 1 1
// 3	// 1 1 1 1 1 1 1 1 1 1 1