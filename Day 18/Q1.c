#include <stdio.h>

// Function to reverse a portion of the array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, k;
    scanf("%d", &n);   // Read size of array
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  // Read array elements
    }
    
    scanf("%d", &k);   // Read rotation count
    k = k % n;         // Handle cases where k > n
    
    // Step 1: Reverse entire array
    reverse(arr, 0, n - 1);
    // Step 2: Reverse first k elements
    reverse(arr, 0, k - 1);
    // Step 3: Reverse remaining n-k elements
    reverse(arr, k, n - 1);
    
    // Print rotated array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
