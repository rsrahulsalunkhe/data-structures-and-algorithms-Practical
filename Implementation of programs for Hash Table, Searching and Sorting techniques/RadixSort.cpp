#include <iostream>
using namespace std;

// Function to find the maximum element in the array
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Counting Sort function to sort the array based on a particular digit
void countingSort(int arr[], int size, int exp) {
    const int RADIX = 10;
    int count[RADIX] = {0};
    int* output = new int[size];

    // Store count of occurrences in count[]
    for (int i = 0; i < size; i++) {
        count[(arr[i] / exp) % RADIX]++;
    }

    // Change count[i] so that count[i] contains the actual position of this digit in output[]
    for (int i = 1; i < RADIX; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % RADIX] - 1] = arr[i];
        count[(arr[i] / exp) % RADIX]--;
    }

    // Copy the output array to arr[] so that arr[] contains the sorted numbers according to the current digit
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(int arr[], int size) {
    // Find the maximum element to determine the number of digits
    int max = findMax(arr, size);

    // Perform counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, size, exp);
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

    radixSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}