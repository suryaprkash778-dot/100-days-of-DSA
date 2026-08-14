int missingNum(int *arr, int size) {
    int n = size + 1;          // total numbers should be n
    int hash[n+1];             // hash array of size n+1

    // initialize hash
    for(int i = 1; i <= n; i++) {
        hash[i] = 0;
    }

    // mark presence
    for(int i = 0; i < size; i++) {
        hash[arr[i]] = 1;
    }

    // find missing
    for(int i = 1; i <= n; i++) {
        if(hash[i] == 0) {
            return i;
        }
    }

    return -1; // fallback (shouldn’t happen)
}
