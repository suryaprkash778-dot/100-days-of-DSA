#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

int heap[MAX_SIZE];
int heapSize = 0;

// Helper functions
int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

// Swap utility
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int i) {
    while (i > 0 && heap[parent(i)] > heap[i]) {
        swap(&heap[parent(i)], &heap[i]);
        i = parent(i);
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;
    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert operation
void insert(int x) {
    if (heapSize == MAX_SIZE) return; // overflow protection
    heap[heapSize] = x;
    heapifyUp(heapSize);
    heapSize++;
}

// Peek operation
int peek() {
    if (heapSize == 0) return -1;
    return heap[0];
}

// ExtractMin operation
int extractMin() {
    if (heapSize == 0) return -1;
    int min = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(0);
    return min;
}

int main() {
    int N;
    scanf("%d", &N);

    char op[20];
    int x;
    for (int i = 0; i < N; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        }
    }
    return 0;
}
