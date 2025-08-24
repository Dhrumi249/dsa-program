#include <iostream>
using namespace std;

int main() {
    int n = 5;  

    for (int i = n; i >= 1; i--) {         
        for (int space = 0; space < n - i; space++) {
            cout << " ";                 
        }
        for (int j = 1; j <= i; j++) {
            cout << (j % 2);            
        }
        cout << endl;                    
    }

    return 0;
}
