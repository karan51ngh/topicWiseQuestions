#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	int n1, n2;
	cin >> n1;
	int arr1[n1];
	unordered_map<int, int> mp;

	for (int i = 0; i < n1; i++)
	{
		cin >> arr1[i];
		mp[arr1[i]] = 1;
	}
	cin >> n2;
	for (int i = 0; i < n2; i++)
	{
		int x;
		cin >> x;

		// write your code here
		auto itr = mp.find(x);
		if (itr != mp.end() && itr->second != 0)
		{
			cout << itr->first << endl;
			itr->second = 0;
		}
	}
	// cout << endl;
}