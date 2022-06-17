#include <iostream>
using namespace std;

int powerLogarithmic(int x, int n)
{
	if (n == 1)
		return x;
	else
	{
		return powerLogarithmic(x, n / 2) * powerLogarithmic(x, n - n / 2);
	}
}

int main()
{
	int x, n;
	cin >> x >> n;
	cout << powerLogarithmic(x, n);
}