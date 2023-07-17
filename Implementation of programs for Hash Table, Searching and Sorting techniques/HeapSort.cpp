#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index 'root'
void heapify(int arr[], int size, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    // If the left child is larger than the root
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    // If the right child is larger than the largest so far
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the root, swap and heapify the affected sub-tree
    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, size, largest);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int size) {
    // Build a max heap
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    // Extract elements from the heap one by one
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heapSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}