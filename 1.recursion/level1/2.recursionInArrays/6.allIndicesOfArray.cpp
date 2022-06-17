#include <iostream>
#include <vector>
using namespace std;

void allIndex(vector<int> &arr, int idx, int data, int count)
{
	if (idx == arr.size())
	{
		if (arr[idx] == data)
		{
			cout << idx << endl;
		}
	}
	else
	{
		if (arr[idx] == data)
		{
			cout << idx << endl;
		}
		allIndex(arr, idx + 1, data, count);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int d;
		cin >> d;
		arr.push_back(d);
	}
	int data;
	cin >> data;
	allIndex(arr, 0, data, 0);

	return 0;
}