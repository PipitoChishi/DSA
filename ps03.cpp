#include <iostream>
using namespace std;

int main() {
    int firstArray[8], secondArray[8];
    int index, totalProduct = 1;

    cout << "Enter values for the first array:" << endl;
    
    // Reading input values and calculating the product
    for (index = 0; index < 8; ++index) {
        cin >> firstArray[index];
        totalProduct *= firstArray[index];
    }

    // Calculating values for the second array
    for (index = 0; index < 8; ++index) {
        secondArray[index] = totalProduct / firstArray[index];
    }

    // Displaying the second array values
    for (index = 0; index < 8; ++index) {
        cout << secondArray[index] << endl;
    }

    return 0;
}