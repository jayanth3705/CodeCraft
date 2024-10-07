#include <stdio.h>

// Function to convert decimal to binary and display it
void decimalToBinary(int n) {
    int binary[32];
    int i = 0;

    if (n == 0) {
        printf("0");
        return;
    }

    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }
    int j; 
    for (j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

// Function for Bitwise AND
int AND(int num1, int num2) {
    return num1 & num2;
}

// Function for Bitwise OR
int OR(int num1, int num2) {
    return num1 | num2;
}

// Function for Bitwise XOR
int XOR(int num1, int num2) {
    return num1 ^ num2;
}

// Function for Bitwise NOT
int NOT(int num1) {
    return ~num1;
}

// Function for Left Shift
int leftShift(int num1, int shift) {
    return num1 << shift;
}

// Function for Right Shift
int rightShift(int num1, int shift) {
    return num1 >> shift;
}

// Function for Addition
int add(int num1, int num2) {
    return num1 + num2;
}

// Function for Subtraction
int subtract(int num1, int num2) {
    return num1 - num2;
}

// Function for Multiplication
int multiply(int num1, int num2) {
    return num1 * num2;
}

// Function for Division
int divide(int num1, int num2) {
    if (num2 == 0) {
        printf("Error: Division by zero.\n");
        return -1;
    }
    return num1 / num2;
}

// Function for Remainder
int remainder(int num1, int num2) {
    return num1 % num2;
}

int main() {
    int num1, num2, choice, operation;

    // Input two numbers
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Convert and display numbers in binary
    printf("Binary representation of %d: ", num1);
    decimalToBinary(num1);
    printf("\n");

    printf("Binary representation of %d: ", num2);
    decimalToBinary(num2);
    printf("\n");

    // User selects type of operation
    printf("Select operation type:\n1. Bitwise Operations\n2. Arithmetic Operations\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Select bitwise operation:\n1. AND\n2. OR\n3. XOR\n4. NOT\n5. Left Shift\n6. Right Shift\n");
            scanf("%d", &operation);
            switch (operation) {
                case 1:
                    printf("Bitwise AND: %d (", AND(num1, num2));
                    decimalToBinary(AND(num1, num2));
                    printf(")\n");
                    break;
                case 2:
                    printf("Bitwise OR: %d (", OR(num1, num2));
                    decimalToBinary(OR(num1, num2));
                    printf(")\n");
                    break;
                case 3:
                    printf("Bitwise XOR: %d (", XOR(num1, num2));
                    decimalToBinary(XOR(num1, num2));
                    printf(")\n");
                    break;
                case 4:
                    printf("Bitwise NOT of %d: %d (", num1, NOT(num1));
                    decimalToBinary(NOT(num1));
                    printf(")\n");
                    break;
                case 5:
                    printf("%d left shift by 1: %d (", num1, leftShift(num1, 1));
                    decimalToBinary(leftShift(num1, 1));
                    printf(")\n");
                    break;
                case 6:
                    printf("%d right shift by 1: %d (", num1, rightShift(num1, 1));
                    decimalToBinary(rightShift(num1, 1));
                    printf(")\n");
                    break;
                default:
                    printf("Invalid bitwise operation.\n");
            }
            break;
        case 2:
            printf("Select arithmetic operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Remainder\n");
            scanf("%d", &operation);
            switch (operation) {
                case 1:
                    printf("Addition: %d (", add(num1, num2));
                    decimalToBinary(add(num1, num2));
                    printf(")\n");
                    break;
                case 2:
                    printf("Subtraction: %d (", subtract(num1, num2));
                    decimalToBinary(subtract(num1, num2));
                    printf(")\n");
                    break;
                case 3:
                    printf("Multiplication: %d (", multiply(num1, num2));
                    decimalToBinary(multiply(num1, num2));
                    printf(")\n");
                    break;
                case 4:
                    if (num2 != 0) {
                        printf("Division: %d (", divide(num1, num2));
                        decimalToBinary(divide(num1, num2));
                        printf(")\n");
                    } else {
                        printf("Error: Division by zero.\n");
                    }
                    break;
                case 5:
                    printf("Remainder: %d (", remainder(num1, num2));
                    decimalToBinary(remainder(num1, num2));
                    printf(")\n");
                    break;
                default:
                    printf("Invalid arithmetic operation.\n");
            }
            break;
        default:
            printf("Invalid operation type.\n");
    }

    return 0;
}

