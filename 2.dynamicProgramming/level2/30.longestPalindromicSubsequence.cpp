#include <bits/stdc++.h>
using namespace std;

int f(string s2)
{
	string s1 = s2;
	reverse(s2.begin(), s2.end());

	int n = s1.size();

	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	int maxx = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else
			{
				if (s1[i - 1] == s2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				maxx = max(maxx, dp[i][j]);
			}
		}

	return maxx;
}

int main()
{
	string s;
	cin >> s;
	cout << f(s) << endl;
}