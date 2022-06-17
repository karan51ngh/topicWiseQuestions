#include <iostream>
using namespace std;

void printIncDec(int n)
{
	// write your code here

	if (n == 1)
	{
		cout << 1 << endl;
		cout << 1 << endl;
		return;
	}
	else
	{
		cout << n << endl;
		printIncDec(n - 1);
		cout << n << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	printIncDec(n);
}
