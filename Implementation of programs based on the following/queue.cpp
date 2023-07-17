#include<iostream>
using namespace std;
#define MAX 5
int rear = -1;
int front = -1;
int queue[MAX];

void enQueue(int x)
{
    if (rear == MAX-1)
    {
        cout << "Queue is Full";
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear++;
    queue[rear] = x;
    return;
}

int deQueue()
{
    int x;
    if (front == -1 && rear == -1)
    {
        cout << "Queue is Empty";
        return -1;
    }

    x = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    } else
    {
        front++;
    }
    return x;
}

void display()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is Empty" << endl;
        return;
    }

    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
    {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main()
{
    int choice, value;
    do
    {
        cout << "List of Operations" << endl;
        cout << "1) EnQueue" << endl;
        cout << "2) DeQueue" << endl;
        cout << "3) Display" << endl;
        cout << "4) Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a value to enqueue : ";
            cin >> value;
            enQueue(value);
            break;

        case 2:
            value = deQueue();
            cout << "The Value deleted is : " << value << endl;
            break;

        case 3:
            display();
            break;
        
        default:
            cout << "Exiting";
            choice = 4;
            break;
        }
    } while (choice != 4);
    
}
