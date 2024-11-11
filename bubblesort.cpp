Write a C++ program that implements the Bubble Sort algorithm. The program should:

Accept an integer size from the user, representing the number of elements in the array.
Accept size number of integers from the user and store them in an array.
Sort the array in ascending order using the Bubble Sort algorithm.
Display the sorted array.

Bubble Sort Algorithm
Step-by-Step Algorithm for Bubble Sort:

Input the array:

Prompt the user to enter the size of the array.
Take the input for the array elements.
Bubble Sort Logic:

Loop through the array n-1 times, where n is the size of the array.
For each pass, compare adjacent elements (arr[j] and arr[j+1]):
If arr[j] > arr[j+1], swap them.
After the first pass, the largest element will be at the last position.
With each subsequent pass, the next largest element "bubbles" to its correct position.
The process continues until no more swaps are needed (array is sorted).
Output the sorted array:

After sorting, print the array with its elements in ascending order.


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

    // Bubble Sort Algorithm
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
