#include <iostream>
#include <string>
#include <stack>

using namespace std;

class MinStack
{
	stack<int> data;
	int minVal;

public:
	int size()
	{
		// write your code here
	}

public:
	void push(int val)
	{
		// write your code here
	}

public:
	int pop()
	{
		// write your code here
	}

public:
	int top()
	{
		// write your code here
	}

public:
	int min()
	{
		// write your code here
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