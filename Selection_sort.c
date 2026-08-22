#include <stdio.h>
int find_min(int arr[], int i,int n){
    int min=i;
    while(i<n){
        if(arr[min]>arr[i]){
            min=i;
        }
        i++;
    }
    return min;
}

void selectionSort(int arr[], int n) {
    
    for(int i=0;i<n;i++){
        int min_index=find_min(arr,i,n);
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() {
    int arr[] = {5,4,2,1,6,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
