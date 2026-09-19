#include <stdio.h>
#include <stdlib.h>

// Merge function
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Recursive Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Struct to hold value-frequency pairs
typedef struct {
    int value;
    int freq;
} Pair;

// Function to get top K frequent elements
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    // Step 1: Sort array
    mergeSort(nums, 0, numsSize - 1);

    // Step 2: Count frequencies
    Pair* pairs = malloc(sizeof(Pair) * numsSize);
    int uniqueCount = 0;

    for (int i = 0; i < numsSize;) {
        int val = nums[i];
        int count = 0;
        while (i < numsSize && nums[i] == val) {
            count++;
            i++;
        }
        pairs[uniqueCount].value = val;
        pairs[uniqueCount].freq = count;
        uniqueCount++;
    }

    // Step 3: Find top K by frequency
    int* result = malloc(sizeof(int) * k);
    *returnSize = k;

    for (int i = 0; i < k; i++) {
        int maxIdx = 0;
        for (int j = 1; j < uniqueCount; j++) {
            if (pairs[j].freq > pairs[maxIdx].freq) {
                maxIdx = j;
            }
        }
        result[i] = pairs[maxIdx].value;
        pairs[maxIdx].freq = -1; // Mark as used
    }

    free(pairs);
    return result;
}
