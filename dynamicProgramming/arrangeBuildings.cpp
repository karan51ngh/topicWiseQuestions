// given n, let n be the length of road n, let it haven plots on each side.
// find the number of ways possible so that buildings can be built on the empty plots on both sides,
//  such that there are no consecutive plots with builduings on both.

// similar to https://github.com/karan51ngh/topicWiseQuestions/blob/master/dynamicProgramming/countBinaryStringArray.cpp

#include <iostream>
#include <bits/stdc++.h>
#define int long
#define vi vector<int>
#define deb(x) cout << #x << " is " << x << endl
using namespace std;

void solved();

signed main()
{
	int T = 1;
	// cin >> T;
	while (T--)
		solved();
}
int f2(int n)
{
	vi zero(n + 1);
	vi one(n + 1);
	zero[1] = 1;
	one[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		zero[i] = one[i - 1];
		one[i] = zero[i - 1] + one[i - 1];
	}
	return zero[n] + one[n];
}
int f(int n)
{
	/*
	let a builduing denote 1.
	and empty slot denote 0.
	so this makes it similar to the countBinaryStrings problem.

	*/
	int x = f2(n);
	return x * x;
}
void solved()
{
	int n;
	cin >> n;
	cout << f(n) << endl;
}