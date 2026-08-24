#include <stdlib.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int hash[10001] = {0};  // assuming values <= 10000
    int* result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    int k = 0;

    // Always hash nums1
    for (int i = 0; i < nums1Size; i++) {
        hash[nums1[i]]++;
    }

    // Check nums2 against hash
    for (int j = 0; j < nums2Size; j++) {
        if (hash[nums2[j]] > 0) {
            result[k++] = nums2[j];
            hash[nums2[j]]--;
        }
    }

    *returnSize = k;
    return result;
}

