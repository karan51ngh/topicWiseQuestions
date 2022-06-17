#include <iostream>
#include <vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
string getNum(int x)
{
	return to_string(x);
}
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

			// getMazePaths(sr, sc + 1, dr, dc, psf + 'h', ans);
			// getMazePaths(sr + 1, sc, dr, dc, psf + 'v', ans);
			for (int i = 1; i < dc; i++)
			{
				getMazePaths(sr, sc + i, dr, dc, psf + 'h' + getNum(i), ans);
			}
			for (int j = 1; j < dr; j++)
			{
				getMazePaths(sr + j, sc, dr, dc, psf + 'v' + getNum(j), ans);
			}
			for (int p = 1; p < min(dc, dr); p++)
			{
				getMazePaths(sr + p, sc + p, dr, dc, psf + 'd' + getNum(p), ans);
			}
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