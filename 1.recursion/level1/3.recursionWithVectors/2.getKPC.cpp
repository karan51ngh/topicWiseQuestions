#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> getKPC(string s)
{
	//Write your code here
	if (s.size() == 1)
	{
	}
	else
	{
		char x = s[0];
		string nextt;
		for (int i = 1; i < s.size(); i++)
		{
			nextt += s[i];
		}
		}
}

int main()
{
	string s;
	cin >> s;
	vector<string> ans = getKPC(s);
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