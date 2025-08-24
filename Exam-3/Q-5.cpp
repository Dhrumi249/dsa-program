#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for (int i = n; i >= 1; i--) {   
        for (int space = 1; space <= n - i; space++) {
            cout << "  ";
        }

        for (int j = i; j <= n; j++) {
            cout << j << " ";
        }

        for (int j = n - 1; j >= i; j--) {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}
