int removeElement(int* arr, int arrsize, int val) {
    for(int i=0; i<arrsize; i++){
        for(int j=0; j<arrsize-1; j++){   
            if(arr[j] == val){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    int count = 0;
    for(int i=0; i<arrsize; i++){
        if(arr[i] != val){   
            count++;
        }
    }
    return count;
}
