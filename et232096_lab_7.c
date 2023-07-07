#include <stdio.h>

// Function to swap the values at two indices in the array and update the count of swaps for the index being swapped
void swap(int* a, int* b, int* swaps_a) {
    int t = *a;
    *a = *b;
    *b = t;
    (*swaps_a)++;
}

// Modified Bubble Sort function that keeps track of how many times a value at each index gets swapped
void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j;
    for (i = 0; i < n-1; i++) {       
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1], &swaps[j]);
            }
        }
    }
}

int main() {
    int arr[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n = sizeof(arr) / sizeof(arr[0]);
    int swaps[n];
    
    // Initialize the swaps array with zeros
    for(int i = 0; i < n; i++) {
        swaps[i] = 0;
    }

    // Bubble sort the array while counting the swaps
    bubbleSort(arr, n, swaps);

    // Print out the swaps for each index
    int totalSwaps = 0;
    for(int i = 0; i < n; i++) {
        printf("Number of swaps needed for index %d: %d\n", i, swaps[i]);
        totalSwaps += swaps[i];
    }
    printf("Total number of swaps: %d\n", totalSwaps);

    return 0;
}
