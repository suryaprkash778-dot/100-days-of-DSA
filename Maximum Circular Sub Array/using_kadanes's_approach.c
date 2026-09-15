#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxSubarraySumCircular(int* nums, int numsSize) {
    int total = nums[0];
    int current_max = nums[0], global_max = nums[0];
    int current_min = nums[0], global_min = nums[0];

    for (int i = 1; i < numsSize; i++) {
        total += nums[i];

        current_max = max(nums[i], current_max + nums[i]);
        global_max = max(global_max, current_max);

        current_min = min(nums[i], current_min + nums[i]);
        global_min = min(global_min, current_min);
    }

    // If all numbers are negative, return global_max
    if (global_max < 0) return global_max;

    // Prevent using the entire array as the minimum subarray
    return max(global_max, total - global_min);
}
