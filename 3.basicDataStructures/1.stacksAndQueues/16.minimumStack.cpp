#include <iostream>
#include <string>
#include <stack>

using namespace std;

class MinStack
{

	stack<int> allData;
	stack<int> minData;

public:
	int size()
	{
		// write your code here
		return allData.size();
	}

public:
	void push(int val)
	{
		// write your code here
		if (!(this->allData.empty()))
		{
			if (val < this->minData.top())
				this->minData.push(val);
			else
				this->minData.push(this->minData.top());
			this->allData.push(val);
			return;
		}
		this->minData.push(val);
		this->allData.push(val);
	}

public:
	int pop()
	{
		// write your code here
		int x = this->allData.top();
		this->allData.pop();
		this->minData.pop();
		return x;
	}

public:
	int top()
	{
		// write your code here
		return this->allData.top();
	}

public:
	int min()
	{
		// write your code here
		return this->minData.top();
	}
};

int main()
{
	MinStack st;

	string str;
	cin >> str;

	while (str != "quit")
	{

		if (str == "push")
		{
			int val;
			cin >> val;
			st.push(val);
		}
		else if (str == "pop")
		{
			int val = st.pop();
			if (val != -1)
			{
				cout << val << endl;
			}
		}
		else if (str == "top")
		{
			int val = st.top();
			if (val != -1)
			{
				cout << val << endl;
			}
		}
		else if (str == "size")
		{
			cout << st.size() << endl;
		}
		else if (str == "min")
		{
			int val = st.min();
			if (val != -1)
			{
				cout << val << endl;
			}
		}

		cin >> str;
	}
}