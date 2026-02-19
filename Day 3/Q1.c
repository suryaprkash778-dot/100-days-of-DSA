// Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include<stdio.h>
void linear_search(int *arr,int key,int size){
    int count = 0,index;
    for(int i=0;i<size;i++){
        count++;
        if(key == arr[i]){
            printf("Found at index %d\nComparisons = %d",i,count);
            return ;
        }
    }
    printf("Not Found \nComparisons = %d",count);
    return ;
}
int main(){
    int arr[4] = {1,2,3,4};
    linear_search(arr,5,4);
    return 0;
}
