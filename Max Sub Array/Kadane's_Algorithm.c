int max(int n1,int n2){
    if(n1>n2){
        return n1;
    }
    else{
        return n2;
    }
}
int maxSubArray(int* nums, int numsSize) {
    int current_max = nums[0];
    int global_max = nums[0];
    for(int i=1;i<numsSize;i++){
        current_max = max(nums[i],nums[i]+current_max);
        global_max = max(global_max,current_max);
    }
    return global_max;

}

