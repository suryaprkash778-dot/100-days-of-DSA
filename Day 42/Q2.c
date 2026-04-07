// ---------- Heap Utilities ----------
typedef struct {
    int *arr;
    int size;
    int capacity;
    int isMinHeap; // 1 for min-heap, 0 for max-heap
} Heap;

Heap* createHeap(int capacity, int isMinHeap) {
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->arr = (int*)malloc(sizeof(int) * capacity);
    h->size = 0;
    h->capacity = capacity;
    h->isMinHeap = isMinHeap;
    return h;
}

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

int compare(Heap* h, int a, int b) {
    if (h->isMinHeap) return a > b; // min-heap: parent > child
    else return a < b;              // max-heap: parent < child
}

void heapifyUp(Heap* h, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (compare(h, h->arr[parent], h->arr[idx])) {
            swap(&h->arr[parent], &h->arr[idx]);
            idx = parent;
        } else break;
    }
}

void heapifyDown(Heap* h, int idx) {
    while (1) {
        int left = 2 * idx + 1, right = 2 * idx + 2, best = idx;
        if (left < h->size && compare(h, h->arr[best], h->arr[left])) best = left;
        if (right < h->size && compare(h, h->arr[best], h->arr[right])) best = right;
        if (best != idx) {
            swap(&h->arr[best], &h->arr[idx]);
            idx = best;
        } else break;
    }
}

void push(Heap* h, int val) {
    if (h->size == h->capacity) return; // no resize for simplicity
    h->arr[h->size++] = val;
    heapifyUp(h, h->size - 1);
}

int top(Heap* h) {
    if (h->size == 0) return 0;
    return h->arr[0];
}

int pop(Heap* h) {
    if (h->size == 0) return 0;
    int root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    heapifyDown(h, 0);
    return root;
}

// ---------- MedianFinder ----------
typedef struct {
    Heap* maxHeap; // smaller half
    Heap* minHeap; // larger half
} MedianFinder;

MedianFinder* medianFinderCreate() {
    MedianFinder* mf = (MedianFinder*)malloc(sizeof(MedianFinder));
    mf->maxHeap = createHeap(50000, 0); // max-heap
    mf->minHeap = createHeap(50000, 1); // min-heap
    return mf;
}

void medianFinderAddNum(MedianFinder* mf, int num) {
    if (mf->maxHeap->size == 0 || num <= top(mf->maxHeap)) {
        push(mf->maxHeap, num);
    } else {
        push(mf->minHeap, num);
    }

    // Balance heaps
    if (mf->maxHeap->size > mf->minHeap->size + 1) {
        push(mf->minHeap, pop(mf->maxHeap));
    } else if (mf->minHeap->size > mf->maxHeap->size) {
        push(mf->maxHeap, pop(mf->minHeap));
    }
}

double medianFinderFindMedian(MedianFinder* mf) {
    if (mf->maxHeap->size == mf->minHeap->size) {
        return ((double)top(mf->maxHeap) + (double)top(mf->minHeap)) / 2.0;
    } else {
        return (double)top(mf->maxHeap);
    }
}

// ---------- Free Memory ----------
void medianFinderFree(MedianFinder* obj) {
    if (!obj) return;
    if (obj->maxHeap) {
        free(obj->maxHeap->arr);
        free(obj->maxHeap);
    }
    if (obj->minHeap) {
        free(obj->minHeap->arr);
        free(obj->minHeap);
    }
    free(obj);
}
