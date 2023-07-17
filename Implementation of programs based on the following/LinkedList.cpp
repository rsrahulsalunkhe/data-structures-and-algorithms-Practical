#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void Insert_at_Begin(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Value inserted at the beginning." << endl;
}

void Insert_at_End(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    cout << "Value inserted at the end." << endl;
}

void Insert_at_Pos(int position, int value) {
    Node* newNode = new Node;
    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        cout << "Value inserted at position " << position << "." << endl;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;
    int count = 1;

    while (current != nullptr && count < position) {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        cout << "Invalid position. Value not inserted." << endl;
        return;
    }

    prev->next = newNode;
    newNode->next = current;
    cout << "Value inserted at position " << position << "." << endl;
}

void Delete_at_Begin() {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "Value deleted at the beginning." << endl;
}

void Delete_at_End() {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Value deleted at the end." << endl;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current->next != nullptr) {
        prev = current;
        current = current->next;
    }

    prev->next = nullptr;
    delete current;
    cout << "Value deleted at the end." << endl;
}

void Delete_at_Pos(int position) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Value deleted at position " << position << "." << endl;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;
    int count = 1;

    while (current != nullptr && count < position) {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        cout << "Invalid position. Value not deleted." << endl;
        return;
    }

    prev->next = current->next;
    delete current;
    cout << "Value deleted at position " << position << "." << endl;
}

void Display() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = head;
    cout << "Contents of the list: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void Count() {
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    cout << "Number of elements in the list: " << count << endl;
}

void Search(int value) {
    if (head == nullptr) {
        cout << "List is empty. Cannot search." << endl;
        return;
    }

    Node* current = head;
    int position = 1;
    bool found = false;

    while (current != nullptr) {
        if (current->data == value) {
            cout << "Value " << value << " found at position " << position << "." << endl;
            found = true;
            break;
        }
        current = current->next;
        position++;
    }

    if (!found) {
        cout << "Value " << value << " not found in the list." << endl;
    }
}

void Exit() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    cout << "Exiting." << endl;
}

int main() {
    int choice, value, position;

    do {
        cout << "List of Operations" << endl;
        cout << "1) Insert at Begin" << endl;
        cout << "2) Insert at End" << endl;
        cout << "3) Insert at Position" << endl;
        cout << "4) Delete at Begin" << endl;
        cout << "5) Delete at End" << endl;
        cout << "6) Delete at Position" << endl;
        cout << "7) Display" << endl;
        cout << "8) Count" << endl;
        cout << "9) Search" << endl;
        cout << "10) Exit" << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to insert at the beginning: ";
                cin >> value;
                Insert_at_Begin(value);
                break;
            case 2:
                cout << "Enter a value to insert at the end: ";
                cin >> value;
                Insert_at_End(value);
                break;
            case 3:
                cout << "Enter a value to insert: ";
                cin >> value;
                cout << "Enter a position to insert a value: ";
                cin >> position;
                Insert_at_Pos(position, value);
                break;
            case 4:
                Delete_at_Begin();
                break;
            case 5:
                Delete_at_End();
                break;
            case 6:
                cout << "Enter a position to delete a value: ";
                cin >> position;
                Delete_at_Pos(position);
                break;
            case 7:
                Display();
                break;
            case 8:
                Count();
                break;
            case 9:
                cout << "Enter a value to search: ";
                cin >> value;
                Search(value);
                break;
            case 10:
                Exit();
                break;
            default:
                cout << "Please enter a valid choice." << endl;
        }
    } while (choice != 10);

    return 0;
}
