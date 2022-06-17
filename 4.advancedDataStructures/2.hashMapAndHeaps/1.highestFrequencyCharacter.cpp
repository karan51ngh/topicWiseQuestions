#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin >> str;

	// write your code here
	unordered_map<char, int> m;
	for (int i = 0; i < str.size(); i++)
	{
		m[str[i]] += 1;
	}
	int maxx = -1;
	char maxc = 'a';
	for (auto i = m.begin(); i != m.end(); i++)
	{
		if (maxx < i->second)
		{
			maxx = i->second;
			maxc = i->first;
		}
	}
	cout << maxc << endl;
}