#include <iostream>
#include <bits/stdc++.h>
// #include <string>
using namespace std;

string f(string s)
{
	stack<char> stk;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			continue;
		if (s[i] != ')')
		{
			stk.push(s[i]);
		}
		else
		{
			if (stk.top() == '(')
				return "true";

			while (stk.top() != '(')
				stk.pop();
			stk.pop();
			// if (i + 1 < s.size() && s[i + 1] == ')' && (!stk.empty()) && stk.top() == '(')
			// return "true";  """useless condition"""
		}
	}
	return "false";
}

int main()
{
	string s;
	getline(cin, s);
	cout << f(s) << endl;
}