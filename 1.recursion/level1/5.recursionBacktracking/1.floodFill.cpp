#include <iostream>

#include <vector>

using namespace std;
// asf -> answer so far
void floodfill(vector<vector<int>> maze, int sr, int sc, int n, int m, string asf)
{
	//write your code here
	if (sr == n - 1 && sc == m - 1)
	{
		cout << asf << endl;
	}

	else
	{
		if (sr >= 0 && sc >= 0 && sr < n && sc < m && maze[sr][sc] == 0)
		{
			maze[sr][sc] = 1;
			floodfill(maze, sr - 1, sc, n, m, asf + 't');
			floodfill(maze, sr, sc - 1, n, m, asf + 'l');
			floodfill(maze, sr + 1, sc, n, m, asf + 'd');
			floodfill(maze, sr, sc + 1, n, m, asf + 'r');
			maze[sr][sc] = 0;
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	floodfill(arr, 0, 0, n, m, "");
}