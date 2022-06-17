#include <iostream>
#include <vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
void getMazePaths(int sr, int sc, int dr, int dc, string psf, vector<string> &ans)
{
	if (sr == dr - 1 && sc == dc - 1)
	{
		ans.push_back(psf);
	}
	else
	{
		if ((sr >= 0) && (sr <= dr - 1) && (sc >= 0) && (sc <= dc - 1))
		{
			// cout << sr << "   " << sc << endl;
			getMazePaths(sr, sc + 1, dr, dc, psf + 'h', ans);
			getMazePaths(sr + 1, sc, dr, dc, psf + 'v', ans);
		}
	}
}

void display(vector<string> &arr)
{
	cout << "[";
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i];
		if (i < arr.size() - 1)
			cout << ", ";
	}

	cout << "]" << endl;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> ans;
	getMazePaths(0, 0, n, m, "", ans);
	display(ans);

	return 0;
}