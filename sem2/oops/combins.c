#include <stdio.h>

void print_combinations(int num, int digits[], int size, int index);

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Convert the integer to an array of digits
    int digits[10];
    int size = 0;
    while (num > 0) {
        digits[size] = num % 10;
        num /= 10;
        size++;
    }

    // Reverse the array so that the digits are in the correct order
    for (int i = 0; i < size / 2; i++) {
        int temp = digits[i];
        digits[i] = digits[size - i - 1];
        digits[size - i - 1] = temp;
    }

    // Call the recursive function to print all combinations of the digits
    print_combinations(num, digits, size, 0);

    return 0;
}

void print_combinations(int num, int digits[], int size, int index) {
    // Base case: if we have printed all digits, we can print the current number
    if (index == size) {
        printf("%d\n", num);
        return;
    }

    // Recursive case: we can swap the current digit with all digits to its right
    for (int i = index; i < size; i++) {
        // Swap the digits
        int temp = digits[index];
        digits[index] = digits[i];
        digits[i] = temp;

        // Recursively print the combinations of the remaining digits
        print_combinations(num * 10 + digits[index], digits, size, index + 1);

        // Swap the digits back to their original positions
        temp = digits[index];
        digits[index] = digits[i];
        digits[i] = temp;
    }
}
