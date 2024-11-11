Write a C++ program that implements the Heap Sort algorithm. The program should:

Accept an integer size from the user, representing the number of elements in the array.
Accept size number of integers from the user and store them in an array.
Sort the array in ascending order using the Heap Sort algorithm.
Display the sorted array.

Heap Sort Algorithm
Step-by-Step Algorithm for Heap Sort:

Build a Max Heap:

A max-heap is a binary tree where the value of each node is greater than or equal to the values of its children.
To build the heap, start from the last non-leaf node and perform a "heapify" operation on it, moving upward.
Extract the Maximum Element:

Once the max-heap is built, the maximum element will always be at the root (the first element of the array).
Swap the root element with the last element of the heap.
Reduce the heap size by one (ignoring the last element now).
Perform a "heapify" operation to restore the heap property.
Repeat the Extraction:

Repeat the extraction process (swap the root with the last element) and heapify the remaining elements until the heap size is reduced to 1.
Output the Sorted Array:

After all extractions, the array will be sorted in ascending order.

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left child
    int right = 2 * i + 2; // right child

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    heapSort(arr, size);

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
