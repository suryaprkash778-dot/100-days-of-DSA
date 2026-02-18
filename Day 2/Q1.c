/*Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers.
 Shift remaining elements to the left.*/
#include<stdio.h>
#include<stdlib.h>
void printarray(int *arr,int size){
    for(int i =0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
int deletenum(int *arr,int position,int size){
    int i = position-1;
    for(int i = position-1;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    return size-1;
}
int main(){
    int size,*arr,position;
    printf("enter size of array\n");
    scanf("%d",&size);
    arr = (int*)(malloc(size*sizeof(int)));
    printf("enter elements in array\n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter position at which you want to delete\n");
    scanf("%d",&position);
    printf("array before deletion\n");
    printarray(arr,size);
    printf("\narray after deletion\n");
    size = deletenum(arr,position,size);
    printarray(arr,size);
    free(arr);
    return 0;
}
