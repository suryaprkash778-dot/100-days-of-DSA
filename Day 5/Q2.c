void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int l = m - 1;          // pointer for nums1's valid elements
    int r = n - 1;          // pointer for nums2
    int temp = m + n - 1;   // pointer for placement in nums1

    // Merge from the back
    while (l >= 0 && r >= 0) {
        if (nums1[l] > nums2[r]) {
            nums1[temp] = nums1[l];
            l--;
        } else {
            nums1[temp] = nums2[r];
            r--;
        }
        temp--;
    }

    // Copy remaining nums2 elements (if any)
    while (r >= 0) {
        nums1[temp] = nums2[r];
        r--;
        temp--;
    }
}
