Question:

Write a C++ program that implements the Selection Sort algorithm. The program should:

Accept an integer size from the user, representing the number of elements in the array.
Accept size number of integers from the user and store them in an array.
Sort the array in ascending order using the Selection Sort algorithm.
Display the sorted array.

Selection Sort Algorithm
Step-by-Step Algorithm for Selection Sort:

Start at the beginning of the array.
Find the minimum element in the unsorted part of the array.
Swap the minimum element with the first unsorted element.
Move the boundary of the sorted and unsorted parts one position forward.
Repeat the process for the remaining unsorted part of the array until the entire array is sorted.

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

    // Selection Sort Algorithm
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;

        // Find the minimum element in the remaining unsorted array
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        swap(arr[i], arr[min_index]);
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
