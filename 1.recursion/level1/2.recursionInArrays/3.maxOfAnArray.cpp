#include <iostream>
using namespace std;

int max(int arr[], int idx, int n)
{
	// write your code here
	if (idx == n - 1)
		return arr[idx];
	else
	{
		int a = max(arr, idx + 1, n);
		if (arr[idx] >= a)
			return arr[idx];
		else
			return a;
	}
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int p = max(arr, 0, n);
	cout << p << endl;
}
