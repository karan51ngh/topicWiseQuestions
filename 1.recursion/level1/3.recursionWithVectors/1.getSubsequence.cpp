#include <iostream>
#include <vector>
using namespace std;

void gss(string s, int n, string ssf, vector<string> &ans)
{
	// write your code here
	if (n == s.size())
	{
		ans.push_back(ssf);
	}
	else
	{
		gss(s, n + 1, ssf, ans);
		gss(s, n + 1, ssf + s[n], ans);
	}
}

int main()
{
	string s;
	cin >> s;
	vector<string> ans;
	gss(s, 0, "", ans);
	int cnt = 0;

	cout << '[';
	for (string str : ans)
	{
		if (cnt != ans.size() - 1)
			cout << str << ", ";
		else
			cout << str;
		cnt++;
	}
	cout << ']';
}