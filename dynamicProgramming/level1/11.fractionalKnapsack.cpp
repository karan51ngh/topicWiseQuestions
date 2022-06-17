#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class tuplee
{
public:
	float a;
	int b;
	int c;
	void print()
	{
		cout << a << " " << b << " " << c << " " << endl;
	}
	tuplee(float x, int y, int z)
	{
		this->a = x;
		this->b = y;
		this->c = z;
	}
};
int shouldISwap(tuplee a, tuplee b)
{
	if (a.a < b.a)
		return 0;
	else
		return 1;
}
void f(int n, int cap, vector<tuplee> arr)
{
	int i = 0;
	int bag = cap;
	float value = 0;
	while (bag > 0 && i < n) // cap == 0 or i == n
	{
		if (bag >= arr[i].b)
		{
			value += arr[i].c;
			bag -= arr[i].b;
			i += 1;
		}
		else
		{

			value += (float)arr[i].c * ((float)bag / (float)arr[i].b);
			bag = 0;
			i += 1;
		}
	}
	cout << value;
	if (value == (int)value)
		cout << ".0\n";
	else
		cout << endl;
}

int main()
{
	int n;
	cin >> n;
	vector<int> wt(n);
	vector<int> val(n);
	for (int i = 0; i < n; i++)
	{
		cin >> val[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> wt[i];
	}
	int cap;
	cin >> cap;
	vector<tuplee> arr;
	for (int i = 0; i < n; i++)
	{
		arr.push_back(tuplee((float)val[i] / wt[i], wt[i], val[i]));
	}

	sort(arr.begin(), arr.end(), shouldISwap);

	// for (auto v : arr)
	// 	v.print();
	f(n, cap, arr);
}