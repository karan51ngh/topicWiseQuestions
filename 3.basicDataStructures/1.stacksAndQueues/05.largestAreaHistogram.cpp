#include <bits/stdc++.h>
using namespace std;

int f(vector<int> arr)
{
	stack<int> lstk;
	lstk.push(0);
	vector<int> larea;
	larea.push_back(0);

	for (int i = 1; i < arr.size(); i++)
	{
		while (arr[i] <= arr[lstk.top()])
		{
			lstk.pop();
			if (lstk.empty())
				break;
		}

		if (lstk.empty())
		{
			larea.push_back(i);
		}
		else
		{
			larea.push_back(i - lstk.top() - 1);
		}
		lstk.push(i);
	}

	stack<int> rstk;
	rstk.push(arr.size() - 1);

	vector<int> rarea;
	rarea.push_back(0);

	for (int i = arr.size() - 2; i >= 0; i--)
	{
		while (arr[i] <= arr[rstk.top()])
		{
			rstk.pop();
			if (rstk.empty())
				break;
		}

		if (rstk.empty())
		{
			rarea.push_back(arr.size() - 1 - i);
		}
		else
		{
			rarea.push_back(rstk.top() - i - 1);
		}
		rstk.push(i);
	}
	reverse(rarea.begin(), rarea.end());

	// for (auto v : larea)
	// 	cout << v << " ";
	// cout << endl;

	// for (auto v : rarea)
	// 	cout << v << " ";
	// cout << endl;

	vector<int> ans(arr.size());
	for (int i = 0; i < ans.size(); i++)
	{
		ans[i] = (larea[i] + rarea[i] + 1) * arr[i];
	}
	return *max_element(ans.begin(), ans.end());
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	//write your code here
	cout << f(arr) << endl;
	return 0;
}