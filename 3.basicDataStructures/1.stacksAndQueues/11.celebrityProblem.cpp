#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	// vector<vector<int>> arr(n, vector<int>(n, 0));
	vector<string> arr(n);
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		arr[i] = temp;
	}

	stack<int> stk;
	for (int i = 0; i < n; i++)
	{
		stk.push(i);
	}
	while (stk.size() >= 2)
	{
		int i = stk.top();
		stk.pop();
		int j = stk.top();
		stk.pop();

		// cout << i << "   " << j << endl;

		if (arr[i][j] == '1')
		{
			// cout << "if cond. " << i << " "
			//  << " " << j << " " << arr[i][j] << endl;
			stk.push(j);
		}
		else
		{
			stk.push(i);
		}
	}

	int x = stk.top();
	// cout << " x is " << x << endl;
	for (int i = 0; i < n; i++)
	{
		if (i != x)
		{
			if (arr[i][x] == '0' || arr[x][i] == '1')
			{
				cout << "none" << endl;
				return 0;
			}
		}
	}
	cout << x << endl;
	return 0;
}