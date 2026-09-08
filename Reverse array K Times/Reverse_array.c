
#include <stdio.h>
#include <stdlib.h>

void rotate(int* nums, int numsSize, int k) {
    // Normalize k so it's within bounds
    k = k % numsSize;

    // Allocate memory for rotated array
    int* new_arr = (int*)malloc(numsSize * sizeof(int));

    // Copy last k elements to the front
    for (int i = 0; i < k; i++) {
        new_arr[i] = nums[numsSize - k + i];
    }

    // Copy the remaining elements
    for (int i = k; i < numsSize; i++) {
        new_arr[i] = nums[i - k];
    }

    //overwrite the array
    for(int i=0;i<numsSize;i++){
        nums[i]=new_arr[i];
    }


}
