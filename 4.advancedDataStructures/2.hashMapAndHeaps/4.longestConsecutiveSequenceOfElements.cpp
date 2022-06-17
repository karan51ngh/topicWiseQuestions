#include <bits/stdc++.h>
using namespace std;

void longestConsecutive(vector<int> &num)
{

	//write your code here
	int maxx = *max_element(num.begin(), num.end());
	int minn = *min_element(num.begin(), num.end());

	unordered_map<int, bool> mp;
	for (int i = minn; i <= maxx; i++)
	{
		mp[i] = false;
	}

	for (int i = minn; i <= maxx; i++)
	{
	}
}

int main()
{
	vector<int> arr;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int data;
		cin >> data;
		arr.push_back(data);
	}
	longestConsecutive(arr);

	return 0;
}