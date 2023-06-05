#include <stdio.h>

// Function to merge two sorted subarrays into a single sorted array
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0; // index for left subarray
    int j = 0; // index for right subarray
    int k = 0; // index for merged array

    // Compare elements from both subarrays and merge them in sorted order
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements from the left subarray, if any
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements from the right subarray, if any
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Function to perform Merge Sort on an array
void mergeSort(int arr[], int size) {
    if (size < 2) {
        return; // Base case: If the array size is 0 or 1, it is already sorted
    }

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    // Divide the array into two halves
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    // Recursively sort the two halves
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // Merge the sorted halves
    merge(arr, left, mid, right, size - mid);
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Example usage
int main() {
    int arr[] = {5, 1, 9, 3, 7, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    mergeSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
