#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin >> str;

	// write your code here
	stack<int> stk;
	int x = 1;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'i')
		{
			stk.push(x);
			x++;
			while (!stk.empty())
			{
				cout << stk.top();
				stk.pop();
			}
		}
		if (str[i] == 'd')
		{
			stk.push(x);
			x++;
		}
	}
	stk.push(x);
	while (!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}
}