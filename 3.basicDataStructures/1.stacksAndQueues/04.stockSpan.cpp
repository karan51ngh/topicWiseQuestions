#include <bits/stdc++.h>
using namespace std;
void display(vector<int> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}
}
vector<int> solve(vector<int> arr)
{
	//write your code here
	stack<int> stk;
	vector<int> ans;

	stk.push(1);
	ans.push_back(1);

	for (int i = 1; i < arr.size(); i++)
	{
		while (arr[stk.top() - 1] < arr[i])
		{
			stk.pop();
			if (stk.empty())
				break;
		}
		if (stk.empty())
		{
			ans.push_back(i + 1);
		}
		else
		{
			ans.push_back(i + 1 - stk.top());
		}
		stk.push(i + 1);
	}
	return ans;
}
int main(int argc, char **argv)
{
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	vector<int> span(n, 0);
	span = solve(arr);
	display(span);
	return 0;
}