#include <iostream>
using namespace std;

int stringLength(char* str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int main() {
    char str[100];
    cout << "Enter any string: ";
    cin.getline(str, 100);

    int len = stringLength(str);
    cout << "The length of a string is: " << len << endl;

    return 0;
}
