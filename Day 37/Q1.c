#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    int arr[MAX];
    int size;
} PriorityQueue;

// Insert element into priority queue
void insert(PriorityQueue* pq, int x) {
    pq->arr[pq->size++] = x;
}

// Delete element with highest priority (smallest value)
int delete(PriorityQueue* pq) {
    if (pq->size == 0) return -1;

    int minIndex = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->arr[i] < pq->arr[minIndex]) {
            minIndex = i;
        }
    }

    int deleted = pq->arr[minIndex];
    // Shift elements
    for (int i = minIndex; i < pq->size - 1; i++) {
        pq->arr[i] = pq->arr[i + 1];
    }
    pq->size--;
    return deleted;
}

// Peek element with highest priority
int peek(PriorityQueue* pq) {
    if (pq->size == 0) return -1;

    int minVal = pq->arr[0];
    for (int i = 1; i < pq->size; i++) {
        if (pq->arr[i] < minVal) {
            minVal = pq->arr[i];
        }
    }
    return minVal;
}

int main() {
    int N;
    scanf("%d", &N);

    PriorityQueue pq;
    pq.size = 0;

    for (int i = 0; i < N; i++) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(&pq, x);
        } else if (strcmp(op, "delete") == 0) {
            printf("%d\n", delete(&pq));
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek(&pq));
        }
    }

    return 0;
}
