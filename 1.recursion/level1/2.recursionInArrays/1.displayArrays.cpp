#include <iostream>
using namespace std;

void display(int arr[], int idx, int n)
{
	// write your code here
	if (idx == n - 1)
	{
		cout << arr[n - 1] << endl;
	}
	else
	{
		cout << arr[idx] << endl;
		display(arr, idx + 1, n);
	}
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	display(arr, 0, n);
}
