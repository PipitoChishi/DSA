 #include <iostream>
#include <vector>
#include <algorithm> // For std::sort

using namespace std;

void BinarySearch(const vector<int>& array, int value)
{
    int low = 0;
    int high = array.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // To avoid integer overflow

        if (array[mid] == value)
        {
            cout << "Value is present at index " << mid << endl;
            return;
        }
        else if (array[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << "Value not found in the array." << endl;
}

int main()
{
    int m1;
    cout << "Enter the number of elements you want in the array: ";
    cin >> m1;

    vector<int> array1(m1);
    cout << "Enter " << m1 << " elements of the array: ";
    for (int i = 0; i < m1; ++i)
    {
        cin >> array1[i];
    }

    cout << "Enter the value to be checked in the array: ";
    int value;
    cin >> value;

    sort(array1.begin(), array1.end()); // Sort the array
    BinarySearch(array1, value);

    return 0;
}
