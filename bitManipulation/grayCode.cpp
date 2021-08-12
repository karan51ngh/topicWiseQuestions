// for a given n print the gray codes.
// Use backTracking
#include <iostream>
#include <bits/stdc++.h>
#define int long
#define vs vector<string>
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
int f2(string a)
{
	// to convert the stirngs to integers
	int n = a.size();
	int sum = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] == '1')
			sum += 1 << (n - 1 - i);
	}
	return sum;
}
vs f(int n)
{
	if (n == 1)
	{
		vs temp;
		temp.push_back("0");
		temp.push_back("1");
		return temp;
	}
	else
	{
		vs temp = f(n - 1);
		vs temp2;
		for (auto itr = temp.begin(); itr < temp.end(); itr++)
		{
			temp2.push_back("0" + *itr);
		}
		for (auto itr = temp.end() - 1; itr >= temp.begin(); itr--)
		{
			temp2.push_back("1" + *itr);
		}
		return temp2;
	}
	vs ERROR;
	ERROR.push_back("ERROR");
	return ERROR;
}
void solved()
{
	int n;
	cin >> n;
	vs sol = f(n);
	// for (auto itr = sol.begin(); itr < sol.end(); itr++)
	// {
	// 	cout << *itr << " ";
	// }
	// cout << endl;
	for (auto itr = sol.begin(); itr < sol.end(); itr++)
	{
		cout << f2(*itr) << " ";
	}
	cout << endl;
}