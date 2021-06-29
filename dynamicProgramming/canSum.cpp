// https://www.youtube.com/watch?v=oBt53YbR9Kk&t=4196s
#include <iostream>
#define int long
using namespace std;

int canSum(int N, int n, int arr[])
{
	// cout << arr[0] << arr[1] << endl
	//  << endl;
	int sol[N + 1];
	for (int i = 0; i <= N; i++)
	{
		sol[i] = 0;
	}
	sol[0] = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (sol[i] == 0)
				continue;
			int x;
			x = arr[j] + i;
			// cout << "i is " << i << " j is " << j << " arr[j] is " << arr[j] << " sol[i] is " << sol[i] << " x is " << x << endl;
			if (x <= N)
			{
				sol[x] = 1;
			}
			if (sol[N] == 1)
			{
				return 1;
			}
		}
	}
	return 0;
}

signed main()
{
	int N, n;
	cin >> N >> n;
	int arr[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << canSum(N, n, arr) << endl;
}