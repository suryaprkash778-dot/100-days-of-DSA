//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    static int result[2];
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    
    *returnSize = 0;
    return NULL;
}
