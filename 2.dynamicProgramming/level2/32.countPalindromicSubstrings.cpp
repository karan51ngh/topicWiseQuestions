#include <bits/stdc++.h>
using namespace std;

int f(string s, int n)
{
	vector<vector<int>> dp(n, vector<int>(n, false));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i; j++)
		{
			if (i == 0)
				dp[j][j + i] = true;
			else if (i == 1)
			{
				if (s[j] == s[j + i])
					dp[j][j + i] = true;
				else
					dp[j][j + i] = false;
			}
			else
			{
				if (s[j] == s[j + i])
					dp[j][j + i] = dp[j + 1][j + i - 1];
				else
					dp[j][j + i] = false;
			}
		}
	int count = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (dp[i][j])
				count++;
		}
	return count;
}

int main()
{
	string s;
	cin >> s;

	int n = s.size();
	cout << f(s, n) << endl;
}