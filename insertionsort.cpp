Write a C++ program that implements the Insertion Sort algorithm. The program should:

Accept an integer size from the user, representing the number of elements in the array.
Accept size number of integers from the user and store them in an array.
Sort the array in ascending order using the Insertion Sort algorithm.
Display the sorted array.

Insertion Sort Algorithm
Step-by-Step Algorithm for Insertion Sort:

Start with the second element in the array (index 1). This element is considered "unsorted," and we compare it with the first element.
Compare the current element with the previous element. If the current element is smaller, shift the previous element one position to the right.
Insert the current element into its correct position in the sorted part of the array.
Move to the next element and repeat the process until the entire array is sorted.
This method works by repeatedly taking the next unsorted element and inserting it into the correct position within the sorted portion of the array.

#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Insertion Sort Algorithm
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
