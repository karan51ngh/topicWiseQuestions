#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> arr;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		arr.push_back(pair<int, int>(a, b));
	}

	sort(arr.begin(), arr.end());

	stack<pair<int, int>> stk;
	stk.push(arr[0]);

	for (int i = 1; i < n; i++)
	{
		if (arr[i].first > stk.top().second)
		{
			stk.push(arr[i]);
			continue;
		}
		else
		{
			if (arr[i].second < stk.top().second)
			{
				continue;
			}
			else
			{
				pair<int, int> temp = stk.top();
				stk.pop();
				temp.second = arr[i].second;
				stk.push(temp);
				continue;
			}
		}
	}
	vector<pair<int, int>> arr2;
	while (!stk.empty())
	{
		arr2.push_back(stk.top());
		stk.pop();
	}
	sort(arr2.begin(), arr2.end());

	for (auto v : arr2)
	{
		cout << v.first << " " << v.second << endl;
	}
}