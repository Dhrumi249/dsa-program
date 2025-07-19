#include <stdio.h>

int main() {
    int score;
    char grade;

    printf("Enter your score (0-100): ");
    scanf("%d", &score);

    if (score < 0 || score > 100) {
        printf("Invalid score. Please enter a value between 0 and 100.\n");
        return 0;
    }

    grade = (score >= 90) ? 'A' :
            (score >= 80) ? 'B' :
            (score >= 70) ? 'C' :
            (score >= 60) ? 'D' : 'F';

    printf("Your grade is %c. ", grade);

    switch(grade) {
        case 'A':
            printf("Excellent work!\n");
            break;
        case 'B':
            printf("Well done.\n");
            break;
        case 'C':
            printf("Good job.\n");
            break;
        case 'D':
            printf("You Passed, but you could do better.\n");
            break;
        case 'F':
            printf("Sorry, you failed.\n");
            break;
        default:
            printf("Error in grade assignment.\n");
    }

    if (grade != 'F') {
        printf("Congratulations! You are eligible for the next level.\n");
    } else {
        printf("Please try again next time.\n");
    }

    return 0;
}
