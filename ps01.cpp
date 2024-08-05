#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[8];
    int n = 8;

    cout << "Enter values" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int max_volume = 0, left = 0, right = n - 1;
    while (left < right)
    {
        int height = min(arr[left], arr[right]);
        int width = right - left;
        int volume = height * width;
        max_volume = max(max_volume, volume);

        if (arr[left] > arr[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    cout << "Max volume: " << max_volume << endl;

    // Calculate triangle area (assuming you want the area between the line joining the two points and the x-axis)
    int base = right - left;
    int height = abs(arr[left] - arr[right]);
    int triangle_area = (base * height) / 2;
    cout << "Triangle area: " << triangle_area << endl;

    return 0;
}
