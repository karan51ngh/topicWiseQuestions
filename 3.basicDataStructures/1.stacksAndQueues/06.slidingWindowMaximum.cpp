#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int k;
	cin >> k;

	// write your code here
	stack<int> stk;
	vector<int> gitr;
	stk.push(n - 1);
	gitr.push_back(100001);
	for (int i = n - 2; i >= 0; i--)
	{
		while (arr[i] > arr[stk.top()])
		{
			stk.pop();
			if (stk.empty())
				break;
		}
		if (stk.empty())
			gitr.push_back(100001);
		else
			gitr.push_back(stk.top());
		stk.push(i);
	}
	reverse(gitr.begin(), gitr.end());
	// for (auto v : gitr)
	// {
	// 	if (v != -1)
	// 		cout << arr[v] << " ";
	// 	else
	// 		cout << -1 << " ";
	// }
	// cout << endl;

	int j = 0;
	vector<int> ans(n);
	for (int i = 0; i <= n - k; i++)
	{
		if (gitr[j] > i + k)
			ans[i] = arr[i];
		if (gitr[j] < i + k)
		{
			j = gitr[j];
			while (i < j)
			{
				ans[i] = arr[i];
				i++;
			}
		}
	}

	return 0;
}