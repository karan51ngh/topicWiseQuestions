// https://www.hackerrank.com/challenges/coin-change/problem
#include <iostream>
#include <bits/stdc++.h>
#define int long
using namespace std;
void solved();
int ways(int, int *, int);
signed main()
{
	int T = 1;
	while (T--)
	{
		solved();
	}
}

void solved()
{
	int n, m;
	cin >> n >> m;
	int c[m];
	vector<int> temp;
	for (int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		temp.push_back(t);
	}
	sort(temp.begin(), temp.end());
	for (int i = 0; i < m; i++)
	{
		// cin >> c[i];
		c[i] = temp[i];
	}
	// sort(c[0], c[m]);
	cout << ways(n, c, m) << endl;
}
int ways(int n, int *c, int m)
{
	int cchange[m][n + 1];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j == 0)
			{
				cchange[i][j] = 1;
			}
			else if (j - c[i] < 0)
			{
				if (i == 0)
					cchange[i][j] = 0;
				else
					cchange[i][j] = cchange[i - 1][j];
			}
			else
			{
				int sum = 0;
				for (int k = 0; k <= i; k++)
				{
					if (j - c[k] >= 0)
					{
						sum += cchange[k][j - c[k]];
					}
					else
					{
						sum += cchange[k - 1][j];
					}
				}
				cchange[i][j] = sum;
			}
		}
	}
	// for (int i = 0; i < m; i++)
	// {
	// 	for (int j = 0; j <= n; j++)
	// 	{
	// 		cout << cchange[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	return cchange[m - 1][n];
}