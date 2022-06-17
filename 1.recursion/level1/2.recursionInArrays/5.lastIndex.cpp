#include <iostream>
using namespace std;

int lastIndex(int arr[], int idx, int x, int n)
{
	// write your code here
	if (idx == n - 1)
	{
		if (arr[idx] == x)
			return idx;
		else
			return -1;
	}
	else
	{
		int a = lastIndex(arr, idx + 1, x, n);
		if (a == -1)
		{
			if (arr[idx] == x)
				return idx;
			else
				return -1;
		}
		else
			return a;
	}
}

int main()
{
	int n;
	cin >> n;
	int d;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> d;
	int p = lastIndex(arr, 0, d, n);
	cout << p << endl;
}