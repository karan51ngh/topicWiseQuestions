// https://www.hackerrank.com/challenges/sherlock-and-cost/problem?isFullScreen=true
// similar to 01knapsack
#include <iostream>
#include <bits/stdc++.h>
#define int long
#define vi vector<int>
#define deb(x) cout << #x << " is " << x << endl
using namespace std;

class solution
{
public:
	// void initMemo()
	// {
	// }

	int mod(int x)
	{
		return (x >= 0 ? x : -x);
	}

	int f(vi b, int count)
	{
		if (count == n)
		{
			int sum = 0;
			for (int i = 0; i <= n - 2; i++)
			{
				sum += mod(b[i] - b[i + 1]);
			}

			return sum;
		}
		else
		{
			vi b1 = b;
			vi b2 = b;

			b1[count] = b[count];
			b2[count] = 1;

			// cout << endl;
			// for (int i = 0; i < n; i++)
			// {
			// 	cout << b[i] << " ";
			// }
			// cout << endl;

			return max(f(b1, count + 1), f(b2, count + 1));
		}
	}
	int n;
	int ans;
	solution(vi B1, int n1)
	{
		n = n1;
		// deb(n);
		ans = f(B1, 0);
	}
};

void solved();

signed main()
{
	int T;
	cin >> T;
	while (T--)
		solved();
}
void solved()
{
	int n;
	cin >> n;
	vi B(n);
	for (int i = 0; i < n; i++)
	{
		cin >> B[i];
	}
	solution S1(B, n);
	int ans = S1.ans;
	// deb(ans);
	cout << ans << endl;
}