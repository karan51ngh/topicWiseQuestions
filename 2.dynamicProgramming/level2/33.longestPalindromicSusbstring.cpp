#include <bits/stdc++.h>
using namespace std;
int f(string s)
{
	int n = s.size();
	vector<vector<int>> dp(n, vector<int>(n, false));

	int I = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (i == 0 || i == 1)
			{
				if (s[j] == s[j + i])
				{
					dp[j][j + i] = true;
					I = i;
				}
				else
					dp[j][j + i] = false;
			}
			else
			{
				if (s[j] == s[j + i])
				{
					dp[j][j + i] = dp[j + 1][j + i - 1];
					if (dp[j][j + i])
						I = i;
				}
				else
					dp[j][j + i] = false;
			}
		}
	}
	return I + 1;
}
int main()
{
	string s;
	cin >> s;
	cout << f(s) << endl;
}