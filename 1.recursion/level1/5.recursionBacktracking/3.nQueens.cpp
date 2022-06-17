#include <bits/stdc++.h>
using namespace std;

void printNQueens(vector<vector<int>> chess, string qsf, int row, int n)
{
	//write your code here
	if (row == n - 1)
	{
		for (int i = 0; i < n; i++)
		{
			if (chess[row][i] == 0)
			{
				cout << qsf + to_string(row) + '-' + to_string(i) + ", ." << endl;
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (chess[row][i] == 0)
			{
				chess[row][i] = 1;
				int l = i;
				int r = i;
				for (int j = row + 1; j < n; j++)
				{
					chess[j][i] += 1;
					if (l - 1 >= 0)
					{
						l -= 1;
						chess[j][l] += 1;
					}
					if (r + 1 < n)
					{
						r += 1;
						chess[j][r] += 1;
					}
				}
				printNQueens(chess, qsf + to_string(row) + '-' + to_string(i) + ", ", row + 1, n);
				chess[row][i] = 0;
				l = i;
				r = i;
				for (int j = row + 1; j < n; j++)
				{
					chess[j][i] += 1;
					if (l - 1 >= 0)
					{
						l -= 1;
						chess[j][l] -= 1;
					}
					if (r + 1 < n)
					{
						r += 1;
						chess[j][r] -= 1;
					}
				}
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> chess(n, vector<int>(n, 0));

	printNQueens(chess, "", 0, n);
}