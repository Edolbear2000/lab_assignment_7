#include <stdio.h>

void bubbleSort(int arr[], int swap_count[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap_count[j]++;
                swap_count[j+1]++;

                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printSwapCounts(int swap_count[], int n) {
    for(int i=0; i<n; i++) {
        printf("Index %d: %d swaps\n", i, swap_count[i]);
    }
}

int main() {
    int arr[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int swap_count[n];
    for(int i=0; i<n; i++)
        swap_count[i] = 0;

    bubbleSort(arr, swap_count, n);
    printSwapCounts(swap_count, n);

    return 0;
}
