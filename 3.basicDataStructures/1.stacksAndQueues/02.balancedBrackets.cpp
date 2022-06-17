#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char revBr(char x)
{
	if (x == ')')
		return '(';
	if (x == '}')
		return '{';
	if (x == ']')
		return '[';
}

string f(string s)
{
	stack<char> stk;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			stk.push(s[i]);
		}

		if (s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			if (stk.empty())
				return "false";
			if (stk.top() == revBr(s[i]))
				stk.pop();
		}
		else
			continue;
	}
	if (stk.empty())
		return "true";

	else
		return "false";
}
int main()
{
	string s;
	getline(cin, s);
	cout << f(s) << endl;
}
