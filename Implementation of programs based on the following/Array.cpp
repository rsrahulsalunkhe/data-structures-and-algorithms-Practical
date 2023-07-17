#include <iostream>
using namespace std;

void insertion(int A[], int n, int Pos, int ITEM)
{
    for (int i = n; i >= Pos; i--)
        A[i + 1] = A[i];
    A[Pos] = ITEM;
    n = n + 1;
}

void deletee(int A[], int &N, int Pos)
{
    int item = A[Pos];
    for (int i = Pos; i < N; i++)
        A[i] = A[i + 1];
    N = N - 1;
    cout << item << " is deleted from the array.";
}

void update(int A[], int n, int pos, int item)
{
    A[pos] = item;
    cout << "Array is updated" << endl;
}

void print(int b[], int N)
{
    for (int i = 0; i < N; i++)
        cout << b[i] << " ";
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter the elements of array : ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int pos, item, choice, delitem;
    char ch;

    do
    {
        cout << "List of Operations" << endl;
        cout << "1. Insert Element \n2. Delete Element \n3. Update Element \n4. Print Element" << endl;
        cout << "Enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Position:";
            cin >> pos;
            cout << "Enter Element:";
            cin >> item;
            insertion(arr, n, pos, item);
            break;
        case 2:
            cout << "Enter position of element to be deleted: ";
            cin >> pos;
            if (pos == -1)
            {
                cout << "Element not found";
            }
            deletee(arr, n, pos);
            break;
        case 3:
            cout << "Enter position of element to be update : ";
            cin >> pos;
            cout << "Enter item to be update : ";
            cin >> item;
            update(arr, n, pos, item);
            break;
        case 4:
            print(arr, n);
            break;
        default:
            cout << "wrong choice";
        }
        cout << "\nDo you want to continue?";
        cout << "(Press y/n)";
        cin >> ch;
    } while (ch == 'y');

    return 0;

}