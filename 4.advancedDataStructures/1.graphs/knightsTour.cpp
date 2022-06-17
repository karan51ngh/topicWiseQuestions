#include <bits/stdc++.h>
using namespace std;

//function to display the 2-d array
void display(vector<vector<int>> &chess)
{
	for (int i = 0; i < chess.size(); i++)
	{
		for (int j = 0; j < chess.size(); j++)
		{
			cout << chess[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int validSquare(int x, int y, int n)
{
	if ((x >= 0) && (y >= 0) && (x < n) && (y < n))
	{
		return 1;
	}
	return 0;
}

void printKnightsTour(vector<vector<int>> &chess, int n, int r, int c, int upcomingMove)
{
	if (upcomingMove == n * n)
	{
		chess[r][c] = upcomingMove;
		display(chess);
		chess[r][c] = 0;
		return;
	}

	else
	{
		chess[r][c] = upcomingMove;
		if (validSquare(r - 2, c + 1, n))
		{
			if (chess[r - 2][c + 1] == 0)
			{
				printKnightsTour(chess, n, r - 2, c + 1, upcomingMove + 1);
			}
		}
		if (validSquare(r - 1, c + 2, n))
		{
			if (chess[r - 1][c + 2] == 0)
			{
				printKnightsTour(chess, n, r - 1, c + 2, upcomingMove + 1);
			}
		}
		if (validSquare(r + 1, c + 2, n))
		{
			if (chess[r + 1][c + 2] == 0)
			{
				printKnightsTour(chess, n, r + 1, c + 2, upcomingMove + 1);
			}
		}
		if (validSquare(r + 2, c + 1, n))
		{
			if (chess[r + 2][c + 1] == 0)
			{
				printKnightsTour(chess, n, r + 2, c + 1, upcomingMove + 1);
			}
		}

		if (validSquare(r + 2, c - 1, n))
		{
			if (chess[r + 2][c - 1] == 0)
			{
				printKnightsTour(chess, n, r + 2, c - 1, upcomingMove + 1);
			}
		}
		if (validSquare(r + 1, c - 2, n))
		{
			if (chess[r + 1][c - 2] == 0)
			{
				printKnightsTour(chess, n, r + 1, c - 2, upcomingMove + 1);
			}
		}
		if (validSquare(r - 1, c - 2, n))
		{
			if (chess[r - 1][c - 2] == 0)
			{
				printKnightsTour(chess, n, r - 1, c - 2, upcomingMove + 1);
			}
		}
		if (validSquare(r - 2, c - 1, n))
		{
			if (chess[r - 2][c - 1] == 0)
			{
				printKnightsTour(chess, n, r - 2, c - 1, upcomingMove + 1);
			}
		}
		chess[r][c] = 0;
		return;
	}
}

int main()
{
	int n, x, y;
	cin >> n >> x >> y;

	vector<vector<int>> chess(n, vector<int>(n, 0));
	printKnightsTour(chess, n, x, y, 1);
}