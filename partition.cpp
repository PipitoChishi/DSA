Partition Algorithm:

Input:
A list/array arr[] with n elements.
A pivot value chosen (in this case, the first element of the array, arr[0]).
Output:
The array is rearranged such that:
All elements smaller than the pivot are placed to the left of the pivot.
All elements greater than or equal to the pivot are placed to the right.
  
Steps:
Choose the pivot: Select the pivot element. In this case, the pivot is the first element, i.e., p = arr[0].
Initialize two pointers:
i starts at the leftmost element (i = 0).
j starts at the rightmost element (j = n - 1).
  
Partitioning Loop:
While i < j:
Move the i pointer to the right until an element larger than or equal to the pivot is found.
Move the j pointer to the left until an element smaller than or equal to the pivot is found.
If i < j, swap arr[i] with arr[j].

Final Swap:
After the pointers i and j cross, swap the pivot element (arr[0]) with arr[i]. This places the pivot element in its correct position, 
such that all elements before it are smaller, and all elements after it are larger.
End: The pivot is now in its correct position, and the array is partitioned.

#include <iostream>
#include <algorithm>
using namespace std;

void partition(int arr[], int n) {
    int p = arr[0];   
    int i = 0;   
    int j = n - 1;   

    while (i < j) {
        do {
            i++;
        } while (i < j && arr[i] < p);

        do {
            j--;
        } while (j >= 0 && arr[j] > p);

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(p, arr[i]);
}

int main() {
    int arr[6] = {5, 8, 2, 4, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    partition(arr, n);

    cout << "Array after partitioning:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

