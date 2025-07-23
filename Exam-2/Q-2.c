#include <iostream>
using namespace std;

int main() {
    int num, count = 0;

    cout << "Enter any number: ";
    cin >> num;

    int temp = num;
    do {
        count++;
        temp /= 10;
    } while (temp != 0);

    cout << "Total number of digits: " << count << endl;

    return 0;
}
