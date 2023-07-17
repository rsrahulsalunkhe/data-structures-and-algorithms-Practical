#include<iostream>
using namespace std;
#define MAX 5
int top = -1;
int stack[MAX];

void push(int item)
{
	if (top == MAX - 1)
	{
		cout << "Stack is full : Cannot Push" << endl;
		return;
	}
	top = top + 1;
	stack[top] = item;
	cout << endl;
	return;
}

int pop()
{
	int item;
	if (top == -1)
	{
		cout << "Stack Empty : Cannot Pop" << endl;
		return -1;
	}
	item = stack[top];
	top = top - 1;
	return item;
}

int peek()
{
	int item;
	if (top == -1)
	{
		cout << "Stack Empty : Cannot Peek" << endl;
		return -1;
	}
	item = stack[top];
	return item;
}

void display()
{
	int i = top;
	if (top == -1)
	{
		cout << "Stack is Empty" << endl;
		return;
	}
	cout << "Contents of the Stack are : ";
	for (i = top; i >= 0; i--)
	{
		cout << stack[i] << " ";
	}
	cout << endl;
	return;
}

int main()
{
	int choice, value;

	do
	{
		cout << "List of Operations" << endl;
		cout << "1. Push \n2. Pop \n3. Peek \n4. Display \n5. Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1: cout << "Enter a value to push : ";
			cin >> value;
			push(value);
			break;
		case 2: value = pop();
			cout << "The value popped is : " << value << endl;
			break;
		case 3: value = peek();
			cout << "The value peeked is : " << value << endl;
			break;
		case 4: display();
			break;
		default: cout << "Exiting";
			choice = 5;
		}
	} while (choice != 5);

	return 0;
}
