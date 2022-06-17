#include <bits/stdc++.h>
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

	vector<int> ans;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i <= k; i++)
	{
		pq.push(arr[i]);
	}
	ans.push_back(pq.top());
	pq.pop();
	for (int i = k + 1; i < n; i++)
	{
		pq.push(arr[i]);
		ans.push_back(pq.top());
		pq.pop();
	}
	while (!pq.empty())
	{
		ans.push_back(pq.top());
		pq.pop();
	}
	for (auto v : ans)
		cout << v << " ";
	cout << endl;
}