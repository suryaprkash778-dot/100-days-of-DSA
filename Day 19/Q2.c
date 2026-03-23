
// Kadane's algorithm to find maximum subarray sum
int kadaneMax(int* arr, int n) {
    int max_sum = arr[0], cur_sum = arr[0];
    for (int i = 1; i < n; i++) {
        cur_sum = (arr[i] > cur_sum + arr[i]) ? arr[i] : cur_sum + arr[i];
        max_sum = (max_sum > cur_sum) ? max_sum : cur_sum;
    }
    return max_sum;
}

// Kadane's algorithm to find minimum subarray sum
int kadaneMin(int* arr, int n) {
    int min_sum = arr[0], cur_sum = arr[0];
    for (int i = 1; i < n; i++) {
        cur_sum = (arr[i] < cur_sum + arr[i]) ? arr[i] : cur_sum + arr[i];
        min_sum = (min_sum < cur_sum) ? min_sum : cur_sum;
    }
    return min_sum;
}

int maxSubarraySumCircular(int* nums, int n) {
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += nums[i];
    }

    int max_normal = kadaneMax(nums, n);
    int min_subarray = kadaneMin(nums, n);

    // Edge case: all numbers are negative
    if (max_normal < 0) {
        return max_normal;
    }

    int max_circular = total_sum - min_subarray;
    return (max_normal > max_circular) ? max_normal : max_circular;
}
