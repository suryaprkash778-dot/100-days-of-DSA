#include <stdio.h>

// Helper function to reverse part of the array
void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    if (numsSize == 0) return;
    k = k % numsSize;  // Handle cases where k > numsSize

    // Step 1: Reverse the whole array
    reverse(nums, 0, numsSize - 1);

    // Step 2: Reverse first k elements
    reverse(nums, 0, k - 1);

    // Step 3: Reverse remaining elements
    reverse(nums, k, numsSize - 1);
}

