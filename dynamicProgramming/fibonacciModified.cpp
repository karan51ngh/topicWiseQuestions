// https://www.hackerrank.com/challenges/fibonacci-modified/problem?isFullScreen=true

// use the concept of big integer(to be done)

#include <iostream>
#include <bits/stdc++.h>
#define int long
#define vi vector<int>
#define deb(x) cout << #x << " is " << x << endl
using namespace std;

class solution
{
public:
	void memoInit()
	{
		vi memo(n + 1, -1);
		memo[1] = t1;
		memo[2] = t2;
		Memo = memo;
	}
	vi Memo;
	int t1, t2, n, ans;
	int sq(int x)
	{
		return x * x;
	}
	int f(int N)
	{
		if (N == 2)
			return t2;
		if (N == 1)
			return t1;
		else
		{
			if (Memo[N] != -1)
				return Memo[N];
			else
			{

				Memo[N] = (f(N - 2) + sq(f(N - 1)));
				return Memo[N];
			}
		}
	}
	solution(int a, int b, int c)
	{
		t1 = a;
		t2 = b;
		n = c;
		memoInit();
		ans = f(n);
	}
};
void solved();

signed main()
{
	int T = 1;
	// cin >> T;
	while (T--)
		solved();
}
void solved()
{
	int t1, t2, n;
	cin >> t1 >> t2 >> n;
	solution s1(t1, t2, n);
	int ans = s1.ans;
	cout << ans << endl;
}