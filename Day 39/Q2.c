// Structure to store element and its frequency
typedef struct {
    int num;
    int freq;
} Element;

// Comparison function for sorting by frequency (descending)
int cmp(const void *a, const void *b) {
    return ((Element*)b)->freq - ((Element*)a)->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    // Hash map simulation using arrays
    int map[200001]; // since nums[i] ranges from -10^4 to 10^4
    memset(map, 0, sizeof(map));

    // Count frequencies
    for (int i = 0; i < numsSize; i++) {
        map[nums[i] + 10000]++;
    }

    // Store elements with frequency
    Element* arr = (Element*)malloc(numsSize * sizeof(Element));
    int count = 0;
    for (int i = 0; i < 200001; i++) {
        if (map[i] > 0) {
            arr[count].num = i - 10000;
            arr[count].freq = map[i];
            count++;
        }
    }

    // Sort by frequency
    qsort(arr, count, sizeof(Element), cmp);

    // Prepare result
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = arr[i].num;
    }

    *returnSize = k;
    free(arr);
    return result;
}

