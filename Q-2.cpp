#include <iostream>
using namespace std;

void printCubes(int* arr, int size) {
    cout << "Cubes of all elements:\n";
    for (int i = 0; i < size * size; i++) {
        cout << (*(arr + i)) * (*(arr + i)) << " ";
        if ((i + 1) % size == 0) {
            cout << endl;
        }
    }
}

int main() {
    int size;
    cout << "Enter array's size: ";
    cin >> size;

    int a[10][10];

    cout << "Enter array elements:\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    printCubes(&a[0][0], size);

    return 0;
}
