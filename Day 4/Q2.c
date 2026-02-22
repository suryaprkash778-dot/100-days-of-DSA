int removeElement(int* arr, int arrsize, int val) {
    int left = 0;
    int right = arrsize - 1;

    while (left <= right) {
        if (arr[left] == val) {
            arr[left] = arr[right]; 
            right--;                
        } else {
            left++; 
        }
    }
    return left; 
}
