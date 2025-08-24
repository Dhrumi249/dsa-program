#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the array's size: ";
    cin >> n;

    int arr[n]; 

    cout << "\nEnter array's elements:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> arr[i];
    }

    cout << "\nNegative elements from an Array: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
