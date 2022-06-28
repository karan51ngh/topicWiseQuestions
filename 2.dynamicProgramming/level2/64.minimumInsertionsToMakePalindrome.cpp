#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int minInsertions(string s)
	{
		int n = s.size();

		vector<vector<int>> dp(n, vector<int>(n));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - i; j++)
			{
				if (i == 0)
					dp[j][j + i] = 0;
				else if (i == 1)
				{
					if (s[j] == s[j + i])
						dp[j][j + i] = 0;
					else
						dp[j][j + i] = 1;
				}
				else
				{
					if (s[j] == s[j + i])
						dp[j][j + i] = dp[j + 1][j + i - 1];
					else
					{
						dp[j][j + i] = 1 + min(dp[j + 1][j + i], dp[j][j + i - 1]);
					}
				}
			}
		}
		return dp[0][n - 1];
	}
};
int main()
{
	Solution S1;
	string s;
	cin >> s;
	cout << S1.minInsertions(s);
}