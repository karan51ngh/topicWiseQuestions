#include <iostream>
using namespace std;

void printPermutations(string str, string asf)
{
	// write your code here
	if (str.size() == 0)
		cout << asf << endl;

	for (int i = 0; i < str.size(); i++)
	{
		string temp;
		temp = str.substr(0, i) + str.substr(i + 1);
		printPermutations(temp, asf + str[i]);
	}
}

int main()
{
	string str;
	cin >> str;
	printPermutations(str, "");
}