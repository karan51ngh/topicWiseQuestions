#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int cs(int n)
{
	// write your code here
	vector<int> arr(n + 1);
	arr[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		if (i - 1 >= 0)
			sum += arr[i - 1];
		if (i - 2 >= 0)
			sum += arr[i - 2];
		if (i - 3 >= 0)
			sum += arr[i - 3];
		arr[i] = sum;
	}
	return arr[n];
}

int main()
{
	int n;
	cin >> n;
	cout << cs(n) << endl;
}