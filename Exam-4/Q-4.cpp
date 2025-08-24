#include <iostream>
using namespace std;

int main() {
    int row, col;
    cout << "Enter the array's row size: ";
    cin >> row;
    cout << "Enter the array's column size: ";
    cin >> col;

    int a[100][100];

    cout << "Enter array's elements:\n";
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    int rowNum;
    cout << "\nEnter row number: ";
    cin >> rowNum;

    int rowSum = 0;
    cout << "Elements of row " << rowNum << ": ";
    for(int j = 0; j < col; ++j){
        cout << a[rowNum][j];
        if (j != col - 1) cout << ", ";
        rowSum += a[rowNum][j];
    }
    cout << "\nThe sum of a row " << rowNum << ": " << rowSum << endl;

    int colNum;
    cout << "\nEnter column number: ";
    cin >> colNum;

    int colSum = 0;
    cout << "Elements of column " << colNum << ": ";
    for(int i = 0; i < row; ++i){
        cout << a[i][colNum];
        if (i != row - 1) cout << ", ";
        colSum += a[i][colNum];
    }
    cout << "\nThe sum of column " << colNum << ": " << colSum << endl;

    return 0;
}
