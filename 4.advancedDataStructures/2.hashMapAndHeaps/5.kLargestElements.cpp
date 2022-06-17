#include <bits/stdc++.h>
using namespace std;
int main()
{

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int k;
	cin >> k;

	priority_queue<int, vector<int>, greater<int>> pq; //min heap format

	for (int i = 0; i < k; i++)
		pq.push(arr[i]);

	for (int i = k; i < n; i++)
	{
		if (arr[i] > pq.top())
		{
			pq.pop();
			pq.push(arr[i]);
		}
	}
	vector<int> ans;
	while (!pq.empty())
	{
		// cout << pq.top() <<" ";
		ans.push_back(pq.top());
		pq.pop();
	}
	reverse(ans.begin(), ans.end());
	for (auto v : ans)
		cout << v << " ";
	cout << endl;
}