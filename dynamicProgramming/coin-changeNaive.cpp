// https://www.hackerrank.com/challenges/coin-change/problem
#include <iostream>
using namespace std;
void solved();
int ways(int, int *, int);
signed main()
{
	solved();
}
void solved()
{
	int n, m;
	cin >> n >> m;
	int c[m];
	for (int i = 0; i < m; i++)
	{
		cin >> c[i];
	}
	cout << ways(n, c, m) << endl;
}
int ways(int n, int *c, int m)
{
	if (n == 0)
	{
		return 1;
	}
	if (n < 0)
	{
		return 0;
	}
	else
	{
		int sum = 0;
		for (int i = 0; i < m; i++)
		{
			sum += ways(n - c[i], c, i + 1); //if we replace i+1 with m, we get permutations instead combinations
		}
		return sum;
	}
}