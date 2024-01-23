/*
#include <stdio.h>
#include <string.h>

// Helper method: given two unequal sized bit strings, converts them to
// the same length by adding leading 0s in the smaller string. Returns the
// new length
int makeEqualLength(const char *str1, const char *str2, char *result1, char *result2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    if (len1 < len2) {
        strcpy(result1, str1);  // Copy the original string to result1
        for (int i = 0; i < len2 - len1; i++)
            strcat(result1, "0");  // Append leading zeros to result1
        strcpy(result2, str2);  // Copy the original string to result2
        return len2;
    } else if (len1 > len2) {
        strcpy(result2, str2);  // Copy the original string to result2
        for (int i = 0; i < len1 - len2; i++)
            strcat(result2, "0");  // Append leading zeros to result2
        strcpy(result1, str1);  // Copy the original string to result1
    } else {
        strcpy(result1, str1);  // If lengths are already equal, no modification needed
        strcpy(result2, str2);
    }
    return len1;  // If len1 >= len2
}

// The main function that adds two bit sequences and returns the addition
void addBitStrings(const char *first, const char *second, char *result) {
    // make the lengths same before adding
    int length = makeEqualLength(first, second, result, result);
    int carry = 0; // Initialize carry

    // Add all bits one by one
    for (int i = length - 1; i >= 0; i--) {
        int firstBit = first[i] - '0';
        int secondBit = second[i] - '0';

        // boolean expression for sum of 3 bits
        int sum = (firstBit ^ secondBit ^ carry) + '0';

        result[length - 1 - i] = (char)sum;

        // boolean expression for 3-bit addition
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }

    // if overflow, then add a leading 1
    if (carry)
        result[0] = '1';
    else
        result[0] = '0';
    result[length] = '\0';
}

// A utility function to multiply single bits of strings a and b
int multiplyiSingleBit(char a, char b) {
    return (a - '0') * (b - '0');
}

// The main function that multiplies two bit strings X and Y and returns
// result as long integer
long int multiply(const char *X, const char *Y) {
    // Find the maximum of lengths of X and Y and make length
    // of smaller string the same as that of the larger string
    char X_mod[100];  // Choose an appropriate size
    char Y_mod[100];  // Choose an appropriate size
    int n = makeEqualLength(X, Y, X_mod, Y_mod);

    // Base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return multiplyiSingleBit(X[0], Y[0]);

    int fh = n / 2;  // First half of string, floor(n/2)
    int sh = (n - fh); // Second half of string, ceil(n/2)

    // Find the first half and second half of the first string
    char Xl[fh + 1], Xr[sh + 1];
    strncpy(Xl, X_mod, fh);
    Xl[fh] = '\0';
    strncpy(Xr, X_mod + fh, sh);
    Xr[sh] = '\0';

    // Find the first half and second half of the second string
    char Yl[fh + 1], Yr[sh + 1];
    strncpy(Yl, Y_mod, fh);
    Yl[fh] = '\0';
    strncpy(Yr, Y_mod + fh, sh);
    Yr[sh] = '\0';

    // Recursively calculate the three products of inputs of size n/2
    long int P1 = multiply(Xl, Yl);
    long int P2 = multiply(Xr, Yr);

    char XlXr[fh + sh + 1], YlYr[fh + sh + 1];
    addBitStrings(Xl, Xr, XlXr);
    addBitStrings(Yl, Yr, YlYr);

    long int P3 = multiply(XlXr, YlYr);

    // Combine the three products to get the final result.
    return P1 * (1 << (2 * sh)) + (P3 - P1 - P2) * (1 << sh) + P2;
}

// Driver program to test above functions
int main() {
    printf("%ld\n", multiply("1100", "1010"));
    printf("%ld\n", multiply("110", "1010"));
    printf("%ld\n", multiply("11", "1010"));
    printf("%ld\n", multiply("1", "1010"));
    printf("%ld\n", multiply("0", "1010"));
    printf("%ld\n", multiply("111", "111"));
    printf("%ld\n", multiply("11", "11"));

    return 0;
}
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to multiply a string by a power of 10
char* multiplyByPowerOfTen(char* num, int power) {
    int len = strlen(num);
    char* result = (char*)malloc((len + power + 1) * sizeof(char));

    for (int i = 0; i < len; i++) {
        result[i] = num[i];
    }

    for (int i = 0; i < power; i++) {
        result[len + i] = '0';
    }

    result[len + power] = '\0';

    return result;
}

// Function to add two strings
char* add(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxSize = (lenA > lenB) ? lenA : lenB;

    char* result = (char*)malloc((maxSize + 2) * sizeof(char));
    result[maxSize + 1] = '\0';

    int carry = 0;
    for (int i = 0; i < maxSize; i++) {
        int digitA = (i < lenA) ? (a[lenA - 1 - i] - '0') : 0;
        int digitB = (i < lenB) ? (b[lenB - 1 - i] - '0') : 0;

        int sum = digitA + digitB + carry;
        result[maxSize - i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    result[0] = carry + '0';
    if (result[0] == '0') {
        // No leading zero if there is no carry
        memmove(result, result + 1, maxSize);
    }

    return result;
}

// Function to subtract two strings (assumes a is greater than or equal to b)
char* subtract(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);

    char* result = (char*)malloc((lenA + 1) * sizeof(char));
    result[lenA] = '\0';

    int borrow = 0;
    for (int i = 0; i < lenA; i++) {
        int digitA = a[lenA - 1 - i] - '0';
        int digitB = (i < lenB) ? (b[lenB - 1 - i] - '0') : 0;

        int diff = digitA - digitB - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result[lenA - i - 1] = diff + '0';
    }

    // Remove leading zeros
    int leadingZeros = 0;
    while (result[leadingZeros] == '0' && result[leadingZeros + 1] != '\0') {
        leadingZeros++;
    }

    if (leadingZeros > 0) {
        memmove(result, result + leadingZeros, lenA - leadingZeros);
        result[lenA - leadingZeros] = '\0';
    }

    return result;
}

// Function to multiply two strings using Karatsuba algorithm
char* karatsuba(char* X, char* Y) {
    int lenX = strlen(X);
    int lenY = strlen(Y);

    // Base case: if either X or Y is a single-digit number
    if (lenX == 1 || lenY == 1) {
        int result = (X[0] - '0') * (Y[0] - '0');
        char* resultStr = (char*)malloc(2 * sizeof(char));
        sprintf(resultStr, "%d", result);
        return resultStr;
    }

    // Calculate the size of the numbers to split
    int maxSize = (lenX > lenY) ? lenX : lenY;
    int halfSize = maxSize / 2;

    // Split X and Y into halves
    char* Xl = (lenX <= halfSize) ? strdup("0") : X;
    char* Xr = (lenX <= halfSize) ? strdup(X) : X + (lenX - halfSize);
    char* Yl = (lenY <= halfSize) ? strdup("0") : Y;
    char* Yr = (lenY <= halfSize) ? strdup(Y) : Y + (lenY - halfSize);

    // Recursively calculate three products
    char* P1 = karatsuba(Xl, Yl);
    char* P2 = karatsuba(Xr, Yr);
    char* P3 = karatsuba(add(Xl, Xr), add(Yl, Yr));

    // Calculate the result using the three products
    char* term1 = multiplyByPowerOfTen(P1, 2 * halfSize);
    char* term2 = subtract(subtract(P3, P1), P2);
    char* result = add(add(term1, term2), P2);

    // Free dynamically allocated memory
    free(P1);
    free(P2);
    free(P3);
    free(term1);
    free(term2);

    return result;
}

int main(void) {
    char X[] = "1234";
    char Y[] = "9876";

    char* result = karatsuba(X, Y);

    printf("Multiplication Result: %s\n", result);

    // Free dynamically allocated memory
    free(result);

    return 0;
}

