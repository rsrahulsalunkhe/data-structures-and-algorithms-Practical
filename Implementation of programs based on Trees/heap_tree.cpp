#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Helper function to maintain the Max-Heap property
    void maxHeapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            maxHeapify(largest);
        }
    }

public:
    // Insert an element into the Max-Heap
    void insert(int value) {
        heap.push_back(value);

        int index = heap.size() - 1;
        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    // Delete the root element (maximum) from the Max-Heap
    void deleteMax() {
        if (heap.empty()) return;

        swap(heap[0], heap.back());
        heap.pop_back();
        maxHeapify(0);
    }

    // Get the maximum element (root) from the Max-Heap without removing it
    int peekMax() const {
        if (heap.empty())
            throw runtime_error("Heap is empty.");
        return heap[0];
    }

    // Get the size of the Max-Heap
    int size() const {
        return heap.size();
    }

    // Check if the Max-Heap is empty
    bool isEmpty() const {
        return heap.empty();
    }

    // Function to display the Max-Heap
    void displayHeap() const {
        if (heap.empty()) {
            cout << "Heap is empty." << endl;
            return;
        }

        cout << "Max-Heap: ";
        for (int i : heap)
            cout << i << " ";
        cout << endl;
    }
};

// Function to display the menu and get user's choice
int displayMenu() {
    int choice;
    cout << "\nMax-Heap Operations:" << endl;
    cout << "1. Insert element" << endl;
    cout << "2. Delete maximum element" << endl;
    cout << "3. Get maximum element" << endl;
    cout << "4. Display Max-Heap" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int main() {
    MaxHeap maxHeap;

    int choice;
    do {
        choice = displayMenu();
        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the element to insert: ";
                cin >> value;
                maxHeap.insert(value);
                break;
            }
            case 2:
                maxHeap.deleteMax();
                break;
            case 3: {
                if (maxHeap.isEmpty())
                    cout << "Heap is empty." << endl;
                else
                    cout << "Maximum element: " << maxHeap.peekMax() << endl;
                break;
            }
            case 4:
                maxHeap.displayHeap();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
