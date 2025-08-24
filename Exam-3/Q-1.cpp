#include <iostream>
using namespace std;

int main() {
    int start = 41;

    for (int i = 1; i <= 5; i++) {        
        for (int j = 0; j < i; j++) {     
            cout << start + j << " ";     
        }
        cout << endl; 
    }

    return 0;
}
