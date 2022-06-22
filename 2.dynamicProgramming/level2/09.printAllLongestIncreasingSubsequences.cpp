#include <bits/stdc++.h>
using namespace std;
void f(vector<int> dp, vector<int> arr, int src, int sizee)
{
	queue<int> qctr;
	queue<vector<int>> paths;
	vector<int> psf;
	psf.push_back(src);

	qctr.push(src);
	paths.push(psf);
	while (!paths.empty())
	{
		int ctr = qctr.front();
		psf = paths.front();

		qctr.pop();
		paths.pop();
		if (dp[psf[psf.size() - 1]] == 1 && dp[psf[0]] == sizee)
		{
			for (int i = psf.size() - 1; i > 0; i--)
			{
				cout << arr[psf[i]] << " -> ";
			}
			cout << arr[psf[0]] << endl;
			continue;
		}

		for (int i = ctr - 1; i >= 0; i--)
		{
			if (dp[i] == dp[ctr] - 1 && arr[i] < arr[ctr])
			{
				vector<int> psf_copy = psf;
				psf_copy.push_back(i);
				qctr.push(i);
				paths.push(psf_copy);
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

	vector<int> dp(n, 1);

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], 1 + dp[j]);
		}
	}

	// for (auto v : dp)`

	int maxx = *max_element(dp.begin(), dp.end());
	cout << maxx << endl;

	for (int i = 0; i < dp.size(); i++)
	{
		if (dp[i] == maxx)
		{
			f(dp, arr, i, maxx);
		}
	}
	// f(dp, arr, (max_element(dp.begin(), dp.end()) - dp.begin()), maxx);
}