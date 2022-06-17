#include <bits/stdc++.h>
using namespace std;
int main()
{
	//write your code here
	int n1;
	cin >> n1;
	unordered_map<int, int> m;
	for (int i = 0; i < n1; i++)
	{
		int x;
		cin >> x;
		m[x] += 1;
	}
	int n2;
	cin >> n2;
	for (int i = 0; i < n2; i++)
	{
		int x;
		cin >> x;

		if (m.find(x) != m.end())
		{
			if (m[x] > 0)
			{
				cout << x << endl;
				m[x] -= 1;
			}
		}
	}
}