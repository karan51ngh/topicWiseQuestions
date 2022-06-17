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
	// write your code here
	stack<int> stk;
	vector<int> sol;
	sol.push_back(-1);
	stk.push(*(arr.end() - 1));

	for (int i = arr.size() - 2; i >= 0; i--)
	{
		while (!stk.empty() && stk.top() <= arr[i])
			stk.pop();
		if (stk.empty())
			sol.push_back(-1);
		else
			sol.push_back(stk.top());
		stk.push(arr[i]);
	}

	reverse(sol.begin(), sol.end());
	return sol;
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
	vector<int> nge(n, 0);
	nge = solve(arr);
	display(nge);
	return 0;
}