#include <iostream>
using namespace std;

int main() {
    int numbers[10], x, y, z;
    
    cout << "Please input 10 numbers:" << endl;
    
    // Reading input values
    for (x = 0; x < 10; ++x) {
        cin >> numbers[x];
    }
    
    
    for (x = 0; x < 10; ++x) {
        for (y = x + 1; y < 10; ++y) {
            for (z = 0; z < 10; ++z) {
                if (numbers[x] + numbers[y] == numbers[z]) {
                    cout << (x + 1) << " and " << (y + 1) << " sum to " << (z + 1) << endl;
                }
            }
        }
    }

    return 0;
}