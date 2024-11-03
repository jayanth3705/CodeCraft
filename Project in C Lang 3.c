#include <stdio.h>
#include <math.h>

void displayMenu() {
    printf("\nCalculator Menu:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Remainder (%%)\n");
    printf("6. Square Root\n");
    printf("7. Power\n");
    printf("8. Percentage\n");
    printf("9. Sine\n");
    printf("10. Cosine\n");
    printf("11. Tangent\n");
    printf("12. Exit\n");
    printf("Choose an option (1-12): ");
}
int main() {
    int choice;
    double num1, num2, result;
    printf(" 1  2  3  +\n 4  5  6  -\n 7  8  9  *\n /  0   %%\n sin  cosin  tan\n");

    
    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }
        switch (choice) {
            case 1: // Addition
                printf("Enter 1st number: ");
                scanf("%lf", &num1);
                printf("Enter 2nd number: ");
                scanf("%lf", &num2);
                result = num1 + num2;
                printf("Result: %.2lf\n", result);
                break;
                
            case 2: // Subtraction
                printf("Enter 1st number: ");
                scanf("%lf", &num1);
                printf("Enter 2nd number: ");
                scanf("%lf", &num2);
                result = num1 - num2;
                printf("Result: %.2lf\n", result);
                break;
                
            case 3: // Multiplication
                printf("Enter 1st number: ");
                scanf("%lf", &num1);
                printf("Enter 2nd number: ");
                scanf("%lf", &num2);
                result = num1 * num2;
                printf("Result: %.2lf\n", result);
                break;
                
            case 4: // Division
                printf("Enter 1st number: ");
                scanf("%lf", &num1);
                printf("Enter 2nd number: ");
                scanf("%lf", &num2);
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("Result: %.2lf\n", result);
                } else {
                    printf("Error: Division by zero!\n");
                }
                break;
                
            case 5: // Remainder
                printf("Enter two integers: ");
                int n1, n2, remainder;
                if (scanf("%d %d", &n1, &n2) != 2) {
                    printf("Invalid input for integers.\n");
                    while (getchar() != '\n');  // Clear input buffer
                    break;
                }
                if (n2 != 0) {
                    remainder = n1 % n2;
                    printf("Remainder: %d\n", remainder);
                } else {
                    printf("Error: Division by zero!\n");
                }
                break;
                
            case 6: // Square Root
                printf("Enter a number: ");
                scanf("%lf", &num1);
                if (num1 >= 0) {
                    result = sqrt(num1);
                    printf("Square Root: %.2lf\n", result);
                } else {
                    printf("Error: Negative input for square root!\n");
                }
                break;
                
            case 7: // Power
                printf("Enter base: ");
                scanf("%lf", &num1);
                printf("Enter power: ");
                scanf("%lf", &num2);
                result = pow(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
                
            case 8: // Percentage
                printf("Enter Score: ");
                scanf("%lf", &num1);
                printf("Enter Total: ");
                scanf("%lf", &num2);
                if (num2 != 0) {
                    result = (num1 * 100) / num2;
                    printf("Percentage: %.2lf%%\n", result);
                } else {
                    printf("Error: Division by zero!\n");
                }
                break;
                
            case 9: // Sine
                printf("Enter the angle in degrees: ");
                scanf("%lf", &num1);
                result = sin(num1 * M_PI / 180.0);  // Convert degrees to radians
                printf("Sine: %.2lf\n", result);
                break;
                
            case 10: // Cosine
                printf("Enter the angle in degrees: ");
                scanf("%lf", &num1);
                result = cos(num1 * M_PI / 180.0);  // Convert degrees to radians
                printf("Cosine: %.2lf\n", result);
                break;
                
            case 11: // Tangent
                printf("Enter the angle in degrees: ");
                scanf("%lf", &num1);
                result = tan(num1 * M_PI / 180.0);  // Convert degrees to radians
                printf("Tangent: %.2lf\n", result);
                break;
                
            case 12: // Exit
                printf("Thank you for using my calculator. Goodbye!\n");
                return 0;
                
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

