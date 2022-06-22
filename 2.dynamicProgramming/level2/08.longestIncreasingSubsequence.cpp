	#include <bits/stdc++.h>
	using namespace std;
	int main()
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		vector<int> dp(n, 1);

		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (arr[j] < arr[i])
					dp[i] = max(dp[i], 1 + dp[j]);
			}
		}
		cout << *max_element(dp.begin(), dp.end()) << endl;
	}