 #include <iostream>

using namespace std;

void LinearSearch(const int array[], int value, int n)
{
    bool found = false;

    for (int i = 0; i < n; ++i)
    {
        if (array[i] == value)
        {
            cout << "Value " << value << " is present at index " << i << endl;
            found = true;
            break; // No need to continue searching once found
        }
    }

    if (!found)
    {
        cout << "Element " << value << " is not found in the array." << endl;
    }
}

int main()
{
    int m1;
    cout << "Enter the number of elements you want in the array: ";
    cin >> m1;

    int array1[m1];
    cout << "Enter " << m1 << " elements of the array: ";
    for (int i = 0; i < m1; ++i)
    {
        cin >> array1[i];
    }

    cout << "Enter the value to be checked in the array: ";
    int value;
    cin >> value;

    LinearSearch(array1, value, m1);

    return 0;
}
