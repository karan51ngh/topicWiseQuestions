#include <bits/stdc++.h>
using namespace std;

int f(vector<int> arr)
{
	int n = arr.size();
	int curr = arr[0];
	int best = arr[0];

	for (int i = 1; i < n; i++)
	{
		curr = max(curr + arr[i], arr[i]);
		best = max(best, curr);
	}
	return best;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << f(arr) << endl;
}