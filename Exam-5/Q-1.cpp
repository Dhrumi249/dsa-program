#include <iostream>
using namespace std;

// UDFs
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) {
    if (b == 0) {
        cout << "Error: Cannot divide by zero." << endl;
        return 0;
    }
    return a / b;
}
int mod(int a, int b) {
    if (b == 0) {
        cout << "Error: Cannot take modulus with zero." << endl;
        return 0;
    }
    return a % b;
}

int main() {
    int choice, a, b;

    while (true) {
        cout << "\nPress 1 for +\n";
        cout << "Press 2 for -\n";
        cout << "Press 3 for *\n";
        cout << "Press 4 for /\n";
        cout << "Press 5 for %\n";
        cout << "Press 0 to exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting calculator. Thank you!" << endl;
            break;
        }

        cout << "Enter the first number: ";
        cin >> a;
        cout << "Enter the second number: ";
        cin >> b;

        switch (choice) {
            case 1:
                cout << "Addition of " << a << " and " << b << " is " << add(a, b) << endl;
                break;
            case 2:
                cout << "Subtraction of " << a << " and " << b << " is " << subtract(a, b) << endl;
                break;
            case 3:
                cout << "Multiplication of " << a << " and " << b << " is " << multiply(a, b) << endl;
                break;
            case 4:
                cout << "Division of " << a << " and " << b << " is " << divide(a, b) << endl;
                break;
            case 5:
                cout << "Modulus of " << a << " and " << b << " is " << mod(a, b) << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}
