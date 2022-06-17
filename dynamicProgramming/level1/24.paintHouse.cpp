#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<int> r, vector<int> b, vector<int> g)
{
	vector<int> ewr(n); //ends with red
	vector<int> ewb(n);
	vector<int> ewg(n);

	ewr[0] = r[0];
	ewb[0] = b[0];
	ewg[0] = g[0];

	for (int i = 1; i < n; i++)
	{
		ewr[i] = r[i] + min(ewb[i - 1], ewg[i - 1]);
		ewb[i] = b[i] + min(ewr[i - 1], ewg[i - 1]);
		ewg[i] = g[i] + min(ewr[i - 1], ewb[i - 1]);
	}

	return min({ewr[n - 1], ewb[n - 1], ewg[n - 1]});
}

int main()
{
	int n;
	cin >> n;
	vector<int> red(n);
	vector<int> blue(n);
	vector<int> green(n);

	for (int i = 0; i < n; i++)
	{
		cin >> red[i];
		cin >> blue[i];
		cin >> green[i];
	}

	cout << f(n, red, blue, green) << endl;
}