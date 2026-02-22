#include <stdio.h>
void reverse(int* arr, int arrsize) {
    int left = 0,temp;
    int right = arrsize - 1;
    while (left < right) {
        temp=arr[left];
        arr[left]=arr[right];
        arr[right]=temp;
        left++;
        right--;
    }
    for(int i =0;i<arrsize;i++){
        printf("%d ",arr[i]);
    }
}
int main() {
    int arr[8] = {1,2,3,4,5};
    int arrsize = 5;
    printf("array before reversal: ");
    for(int i =0;i<arrsize;i++){
        printf("%d ",arr[i]);
    }
    printf("\narray after reversal: ");
    reverse(arr,arrsize);

    return 0;
}
