// https://www.hackerrank.com/challenges/equal/problem
/*
we modify the solution a bit.

instead of adding choclates for every employee except 1.
we remove choclates from 1 employee.

we build an array of possible solutions.

and we calculate the total operations required to achieve that solution. (we use greedy approach for that)
and then return the minimum number of operations to do so.

*/
#include <iostream>
#include <bits/stdc++.h>
#define int long
#define vi vector<int>
#define deb(x) cout << #x << " is " << x << endl
using namespace std;

class solution
{
public:
	int ans;
	vi arr;
	int n;
	vi sol;
	void initSolution() //calculate all the possible solutions
	{
		int min = 1001;
		for (int i = 0; i < n; i++)
		{
			if (min > arr[i])
				min = arr[i];
		}
		if (min >= 5)
		{
			for (int i = 0; i <= 5; i++)
			{
				sol.push_back(min - i);
			}
		}
		else
		{
			for (int i = min; i >= 0; i--)
			{
				sol.push_back(i);
			}
		}
	}
	int f2(int a, int b) //use greedy approach
	{
		int x = a - b;
		int opr = 0;

		while (x > 0)
		{
			if (x >= 5)
			{
				x = x - 5;
				opr += 1;
				continue;
			}
			if (x >= 2)
			{
				x = x - 2;
				opr += 1;
				continue;
			}
			if (x >= 1)
			{
				x = x - 1;
				opr += 1;
				continue;
			}
		}
		return opr;
	}

	int f()
	{
		int min = 100000;
		for (auto itr = sol.begin(); itr < sol.end(); itr++)
		{
			int opr = 0;
			for (int j = 0; j < n; j++)
			{
				opr += f2(arr[j], *itr);
			}
			if (opr < min)
				min = opr;
		}

		return min;
	}

	solution(vi a, int N)
	{
		arr = a;
		n = N;
		initSolution();
		ans = f();
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
	int N;
	cin >> N;
	vi a(N);
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	solution S1(a, N);
	int an = S1.ans;
	cout << an << endl;
}