#include<iostream>
using namespace std;
#define MAX 5
int rear = -1;
int front = -1;
int deque[MAX];

void insertFront(int x)
{
    if ((front == 0 && rear == MAX-1) || (front == rear+1))
    {
        cout << "Deque is Full";
        return;
    }

    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = MAX-1;
    }
    else
    {
        front--;
    }

    deque[front] = x;
    cout << "Element inserted at the front." << endl;
}

void insertRear(int x)
{
    if ((front == 0 && rear == MAX-1) || (front == rear+1))
    {
        cout << "Deque is Full";
        return;
    }

    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX-1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = x;
    cout << "Element inserted at the rear." << endl;
}

void deleteFront()
{
    if (front == -1 && rear == -1)
    {
        cout << "Deque is Empty";
        return;
    }

    cout << "Element deleted from the front: " << deque[front] << endl;
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX-1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void deleteRear()
{
    if (front == -1 && rear == -1)
    {
        cout << "Deque is Empty";
        return;
    }

    cout << "Element deleted from the rear: " << deque[rear] << endl;
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX-1;
    }
    else
    {
        rear--;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        cout << "Deque is Empty" << endl;
        return;
    }

    cout << "Deque elements: ";
    int i = front;
    while (i != rear)
    {
        cout << deque[i] << " ";
        i = (i+1) % MAX;
    }
    cout << deque[rear] << endl;
}

int main()
{
    int choice, value;
    do
    {
        cout << "List of Operations" << endl;
        cout << "1) Insert at Front" << endl;
        cout << "2) Insert at Rear" << endl;
        cout << "3) Delete from Front" << endl;
        cout << "4) Delete from Rear" << endl;
        cout << "5) Display" << endl;
        cout << "6) Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a value to insert at the front: ";
            cin >> value;
            insertFront(value);
            break;

        case 2:
            cout << "Enter a value to insert at the rear: ";
            cin >> value;
            insertRear(value);
            break;

        case 3:
            deleteFront();
            break;

        case 4:
            deleteRear();
            break;

        case 5:
            display();
            break;

        default:
            cout << "Exiting" << endl;
            choice = 6;
            break;
        }
    } while (choice != 6);

    return 0;
}
