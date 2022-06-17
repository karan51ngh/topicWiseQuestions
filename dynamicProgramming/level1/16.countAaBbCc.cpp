#include <bits/stdc++.h>
using namespace std;

int f(string str)
{
	int n = str.size();
	str.insert(0, " ");
	vector<int> a(n + 1);
	vector<int> b(n + 1);
	vector<int> c(n + 1);
	a[0] = 0;
	b[0] = 0;
	c[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		if (str[i] == 'a')
			a[i] = 2 * a[i - 1] + 1;

		else
			a[i] = a[i - 1];
	}

	for (int i = 1; i <= n; i++)
	{
		if (str[i] == 'b')
			b[i] = 2 * b[i - 1] + a[i];

		else
			b[i] = b[i - 1];
	}

	for (int i = 1; i <= n; i++)
	{
		if (str[i] == 'c')
			c[i] = 2 * c[i - 1] + b[i];

		else
			c[i] = c[i - 1];
	}
	// for(auto v: a)
	//     cout << v << " ";
	// cout << endl;

	// for(auto v: b)
	//     cout << v << " ";
	// cout << endl;

	// for(auto v: c)
	//     cout << v << " ";
	// cout << endl;

	return c[n];
}

int main()
{
	string str;
	cin >> str;
	cout << f(str) << endl;
}