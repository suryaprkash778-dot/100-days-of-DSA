#include <stdio.h>

void swap(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[left];   // pivot is the value
    int i = left - 1;
    int j = right + 1;

    while (1) {
        // Move i to the right until arr[i] >= pivot
        do {
            i++;
        } while (arr[i] < pivot);

        // Move j to the left until arr[j] <= pivot
        do {
            j--;
        } while (arr[j] > pivot);

        // If pointers cross, return partition index
        if (i >= j)
            return j;

        // Swap elements at i and j
        swap(&arr[i], &arr[j]);
    }
}

// Recursive Quick Sort function
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int j = partition(arr, left, right);
        quickSort(arr, left, j);      // sort left partition
        quickSort(arr, j + 1, right); // sort right partition
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Unsorted array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

