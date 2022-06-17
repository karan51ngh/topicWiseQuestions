#include <bits/stdc++.h>
using namespace std;
int main()
{

	unordered_map<int, bool> mp;
	mp[0] = false;
	mp[3] = false;
	mp[6] = false;
	mp[4] = false;
	mp[2] = false;

	for (auto v : mp)
		cout << v.first << "   " << v.second << endl;
}