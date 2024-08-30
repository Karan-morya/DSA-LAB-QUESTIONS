#include <stdio.h>

// Function prototypes
int iterativeBinarySearch(int arr[], int size, int target);
int recursiveBinarySearch(int arr[], int low, int high, int target);

int main() {
    int sortedArray[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(sortedArray) / sizeof(sortedArray[0]);
    int target = 7;

    // Iterative binary search
    int indexIterative = iterativeBinarySearch(sortedArray, size, target);
    if (indexIterative != -1) {
        printf("Iterative: The index of %d is %d\n", target, indexIterative);
    } else {
        printf("Iterative: %d not found in the array\n", target);
    }

    // Recursive binary search
    int indexRecursive = recursiveBinarySearch(sortedArray, 0, size - 1, target);
    if (indexRecursive != -1) {
        printf("Recursive: The index of %d is %d\n", target, indexRecursive);
    } else {
        printf("Recursive: %d not found in the array\n", target);
    }

    return 0;
}
