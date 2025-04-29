#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char* addBinary(char* a, char* b) {
    int sizeA = strlen(a);
    int sizeB = strlen(b);
    int smallest;
    int max;
    char *arrayLongest;
    
    // Reverse the input strings into arrays
    char arrayA[sizeA + 1];
    char arrayB[sizeB + 1];
    char arrayC[sizeA + sizeB + 2]; // Enough space for result
    bool carryOut = false;
    int index = 0;

    // Reverse string a into arrayA
    for (int i = sizeA - 1; i >= 0; i--) {
        arrayA[index] = a[i];
        index++;
    }
    arrayA[index] = '\0';

    // Reverse string b into arrayB
    index = 0;
    for (int i = sizeB - 1; i >= 0; i--) {
        arrayB[index] = b[i];
        index++;
    }
    arrayB[index] = '\0';

    // Determine the smallest and largest sizes
    if (sizeA > sizeB) {
        smallest = sizeB;
        max = sizeA;
        arrayLongest = arrayA;
    } else {
        smallest = sizeA;
        max = sizeB;
        arrayLongest = arrayB;
    }

    int sizeC = 0;
    // Add the bits from the smaller array
    for (int i = 0; i < smallest; i++) {
        int sum = (arrayA[i] - '0') + (arrayB[i] - '0');
        if (carryOut) {
            sum++;
        }
        if (sum == 0) {
            arrayC[sizeC] = '0';
            carryOut = false;
        } else if (sum == 1) {
            arrayC[sizeC] = '1';
            carryOut = false;
        } else if (sum == 2) {
            arrayC[sizeC] = '0';
            carryOut = true;
        } else if (sum == 3) {
            arrayC[sizeC] = '1';
            carryOut = true;
        }
        sizeC++;
    }

    // Handle the remaining bits from the longer array
    for (int i = smallest; i < max; i++) {
        int sum = (arrayLongest[i] - '0');
        if (carryOut) {
            sum++;
        }
        if (sum == 0) {
            arrayC[sizeC] = '0';
            carryOut = false;
        } else if (sum == 1) {
            arrayC[sizeC] = '1';
            carryOut = false;
        } else if (sum == 2) {
            arrayC[sizeC] = '0';
            carryOut = true;
        }
        sizeC++;
    }

    // If there's still a carry after the last bit
    if (carryOut) {
        arrayC[sizeC] = '1';
        sizeC++;
    }

    // Allocate memory for the final result and reverse arrayC into it
    char* arrayD = (char*)malloc(sizeC + 1); // +1 for null terminator
    for (int i = 0; i < sizeC; i++) {
        arrayD[i] = arrayC[sizeC - 1 - i];
    }
    arrayD[sizeC] = '\0'; // Null terminate

    return arrayD;
}
