// Min-heap structure
typedef struct {
    int *arr;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->arr = (int*)malloc(sizeof(int) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->arr[parent] > heap->arr[index]) {
            swap(&heap->arr[parent], &heap->arr[index]);
            index = parent;
        } else break;
    }
}

void heapifyDown(MinHeap* heap, int index) {
    while (index * 2 + 1 < heap->size) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int smallest = left;

        if (right < heap->size && heap->arr[right] < heap->arr[left])
            smallest = right;

        if (heap->arr[index] > heap->arr[smallest]) {
            swap(&heap->arr[index], &heap->arr[smallest]);
            index = smallest;
        } else break;
    }
}

void pushHeap(MinHeap* heap, int val) {
    if (heap->size < heap->capacity) {
        heap->arr[heap->size++] = val;
        heapifyUp(heap, heap->size - 1);
    } else if (val > heap->arr[0]) {
        heap->arr[0] = val;
        heapifyDown(heap, 0);
    }
}

int topHeap(MinHeap* heap) {
    return heap->arr[0];
}

// KthLargest structure
typedef struct {
    MinHeap* heap;
    int k;
} KthLargest;

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = createHeap(k);
    obj->k = k;

    for (int i = 0; i < numsSize; i++) {
        pushHeap(obj->heap, nums[i]);
    }
    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    pushHeap(obj->heap, val);
    return topHeap(obj->heap);
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap->arr);
    free(obj->heap);
    free(obj);
}

