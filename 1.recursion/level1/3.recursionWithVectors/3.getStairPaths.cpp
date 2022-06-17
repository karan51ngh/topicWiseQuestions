#include <iostream>
#include <vector>
#include <string>
using namespace std;

void get_stair_paths(int n, int x, string psf, vector<string> &ans)
{
	//Write your code here
	if (x == n)
	{
		ans.push_back(psf);
	}
	if (x > n)
	{
		return;
	}
	else
	{
		get_stair_paths(n, x + 1, psf + '1', ans);
		get_stair_paths(n, x + 2, psf + '2', ans);
		get_stair_paths(n, x + 3, psf + '3', ans);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<string> ans;
	get_stair_paths(n, 0, "", ans);
	int cnt = 0;

	cout << '[';
	for (string str : ans)
	{
		if (cnt != ans.size() - 1)
			cout << str << ", ";
		else
			cout << str;
		cnt++;
	}
	cout << ']';
}