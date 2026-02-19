/*You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). 
This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.*/
int missingNum(int *arr, int size) {
    // code here
    int s1=0,s2=0;
    for(int i = 1; i<=size+1;i++){
        s2+=i;
    }
    for(int i = 0;i<size;i++){
        s1+=arr[i];
    }
    int missing = s2 -s1;
    return missing;
}
