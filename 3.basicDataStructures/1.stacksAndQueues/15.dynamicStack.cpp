#include <iostream>
#include <exception>
using namespace std;

class Stack
{

public:
	int *arr;
	int tos;
	int MaxCapacity;

public:
	Stack(int size)
	{
		this->MaxCapacity = size;
		this->arr = new int[this->MaxCapacity];
		this->tos = -1;
	}

public:
	Stack()
	{
		Stack(10);
	}

public:
	int size()
	{
		// write your code here
		return this->tos + 1;
	}

public:
	void push(int data)
	{

		// write your code here
		if (tos == this->MaxCapacity - 1)
		{

			int *arr2;
			arr2 = new int[2 * (this->MaxCapacity)];
			for (int i = 0; i < this->MaxCapacity; i++)
			{
				*(arr2 + i) = this->arr[i];
			}
			this->MaxCapacity *= 2;
			this->arr = arr2;
		}
		this->tos += 1;
		this->arr[this->tos] = data;
		return;
	}

public:
	int top()
	{
		// write your code here
		if (this->tos == -1)
		{
			cout << "Stack underflow" << endl;
			return -1;
		}
		return this->arr[this->tos];
	}

public:
	int pop()
	{
		// write your code here
		if (this->tos == -1)
		{
			cout << "Stack underflow" << endl;
			return -1;
		}
		int x = this->arr[this->tos];
		this->tos -= 1;
		return x;
	}

public:
	void display()
	{
		// write your code here
		for (int i = this->tos; i >= 0; i--)
		{
			cout << this->arr[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	int n;
	cin >> n;
	Stack st(n);
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
		else if (str == "display")
		{
			st.display();
		}
		cin >> str;
	}
}