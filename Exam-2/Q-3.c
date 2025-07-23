#include <stdio.h>
#include <conio.h> 

int main() {
    int num, firstDigit, lastDigit;

    printf("Enter any number: ");
    scanf("%d", &num);

    lastDigit = num % 10;

    int temp = num;
    while (temp >= 10) {
        temp /= 10;
    }
    firstDigit = temp;

    printf("The sum of the first and the last digit: %d\n", firstDigit + lastDigit);

    return 0;
}
