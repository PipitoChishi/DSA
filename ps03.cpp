#include <iostream>
using namespace std;

int main() {
    int firstArray[8], secondArray[8];
    int index, totalProduct = 1;

    cout << "Enter values for first array:" << endl;
    
    for (index = 0; index < 8; ++index) {
        cin >> firstArray[index];
        totalProduct *= firstArray[index];
    }

    for (index = 0; index < 8; ++index) {
        secondArray[index] = totalProduct / firstArray[index];
    }

    for (index = 0; index < 8; ++index) {
        cout << secondArray[index] << endl;
    }

    return 0;
}
