int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int hash[1001] = {0};   // assuming values are within [0,1000]
    int *new_arr = malloc((nums1Size < nums2Size ? nums1Size : nums2Size) * sizeof(int));
    int k = 0;              // index for result array

    // Count frequencies of nums1
    for (int i = 0; i < nums1Size; i++) {
        hash[nums1[i]]++;
    }

    // Check nums2 against hash
    for (int i = 0; i < nums2Size; i++) {
        if (hash[nums2[i]] > 0) {
            new_arr[k++] = nums2[i];
            hash[nums2[i]]--;
        }
    }

    *returnSize = k;   // actual intersection size
    return new_arr;
}
