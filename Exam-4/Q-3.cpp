#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the array's row & column size: ";
    cin >> n;

    int a[100][100], transpose[100][100];

    cout << "Enter array's elements:" << endl;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            transpose[j][i] = a[i][j];
        }
    }

    cout << "\nThe transpose matrix of an array:\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
