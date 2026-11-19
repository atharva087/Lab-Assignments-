#include <stdio.h>

int main() {
    // Input values
    int num1 = 20;
    int num2 = 4;
    int choice;

    // Prompt user for choice
    printf("Enter choice (1: Add, 2: Subtract, 3: Multiply, 4: Divide): ");
    scanf("%d", &choice);

    // Operation logic
    switch (choice) {
        case 1:
            printf("Addition is=%d\n", num1 + num2);
            break;
        case 2:
            printf("Subtraction is=%d\n", num1 - num2);
            break;
        case 3:
            printf("Multiplication is=%d\n", num1 * num2);
            break;
        case 4:
            if (num2 != 0) {
                printf("Division is=%d\n", num1 / num2);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Invalid choice! Please select an option between 1 and 4.\n");
    }

    return 0;
}

