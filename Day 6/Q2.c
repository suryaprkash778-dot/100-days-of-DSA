void moveZeroes(int* nums, int numsSize) {
    int l=0;
    for(int r=0;r< numsSize;r++){
        if(nums[r]!=0){
            nums[l]=nums[r];
            if(l!=r){
                nums[r]=0;
            }
            l++;
        }
    }
    for(int i =0;i<numsSize;i++){
        printf("%d ",nums[i]);
    }
}
