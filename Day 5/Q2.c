void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int l = m - 1;          
    int r = n - 1;          
    int temp = m + n - 1;   
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
    while (r >= 0) {
        nums1[temp] = nums2[r];
        r--;
        temp--;
    }
}
