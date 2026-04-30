#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

// Min-heap node
typedef struct {
    int node;
    int dist;
} HeapNode;

typedef struct {
    HeapNode* arr;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* heap = malloc(sizeof(MinHeap));
    heap->arr = malloc(capacity * sizeof(HeapNode));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapPush(MinHeap* heap, int node, int dist) {
    heap->arr[heap->size++] = (HeapNode){node, dist};
    int i = heap->size - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap->arr[parent].dist <= heap->arr[i].dist) break;
        swap(&heap->arr[parent], &heap->arr[i]);
        i = parent;
    }
}

HeapNode heapPop(MinHeap* heap) {
    HeapNode root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    int i = 0;
    while (true) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
        if (left < heap->size && heap->arr[left].dist < heap->arr[smallest].dist) smallest = left;
        if (right < heap->size && heap->arr[right].dist < heap->arr[smallest].dist) smallest = right;
        if (smallest == i) break;
        swap(&heap->arr[i], &heap->arr[smallest]);
        i = smallest;
    }
    return root;
}

bool heapEmpty(MinHeap* heap) {
    return heap->size == 0;
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    // adjacency list
    int** graph = malloc((n+1) * sizeof(int*));
    int* graphColSize = calloc(n+1, sizeof(int));
    for (int i = 1; i <= n; i++) {
        graph[i] = malloc(timesSize * sizeof(int));
        graphColSize[i] = 0;
    }
    int** weight = malloc((n+1) * sizeof(int*));
    for (int i = 1; i <= n; i++) {
        weight[i] = malloc(timesSize * sizeof(int));
    }

    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0], v = times[i][1], w = times[i][2];
        graph[u][graphColSize[u]] = v;
        weight[u][graphColSize[u]] = w;
        graphColSize[u]++;
    }

    int* dist = malloc((n+1) * sizeof(int));
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[k] = 0;

    MinHeap* heap = createHeap(timesSize + n);
    heapPush(heap, k, 0);

    while (!heapEmpty(heap)) {
        HeapNode cur = heapPop(heap);
        int u = cur.node;
        int d = cur.dist;
        if (d > dist[u]) continue;
        for (int i = 0; i < graphColSize[u]; i++) {
            int v = graph[u][i];
            int w = weight[u][i];
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                heapPush(heap, v, dist[v]);
            }
        }
    }

    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) return -1;
        if (dist[i] > maxTime) maxTime = dist[i];
    }
    return maxTime;
}
