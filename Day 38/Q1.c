#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int arr[MAX];
    int front, rear, size;
} Deque;

// Initialize deque
void initDeque(Deque* dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
}

// Check if empty
int empty(Deque* dq) {
    return dq->size == 0;
}

// Return size
int size(Deque* dq) {
    return dq->size;
}

// Push front
void push_front(Deque* dq, int value) {
    if (dq->size == MAX) return; // full
    dq->front = (dq->front - 1 + MAX) % MAX;
    dq->arr[dq->front] = value;
    dq->size++;
}

// Push back
void push_back(Deque* dq, int value) {
    if (dq->size == MAX) return; // full
    dq->rear = (dq->rear + 1) % MAX;
    dq->arr[dq->rear] = value;
    dq->size++;
}

// Pop front
int pop_front(Deque* dq) {
    if (empty(dq)) return -1;
    int val = dq->arr[dq->front];
    dq->front = (dq->front + 1) % MAX;
    dq->size--;
    return val;
}

// Pop back
int pop_back(Deque* dq) {
    if (empty(dq)) return -1;
    int val = dq->arr[dq->rear];
    dq->rear = (dq->rear - 1 + MAX) % MAX;
    dq->size--;
    return val;
}

// Front element
int front(Deque* dq) {
    if (empty(dq)) return -1;
    return dq->arr[dq->front];
}

// Back element
int back(Deque* dq) {
    if (empty(dq)) return -1;
    return dq->arr[dq->rear];
}

// Clear deque
void clear(Deque* dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
}

// Print current state
void printDeque(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque: ");
    for (int i = 0; i < dq->size; i++) {
        int idx = (dq->front + i) % MAX;
        printf("%d ", dq->arr[idx]);
    }
    printf("\n");
}

// Example usage
int main() {
    Deque dq;
    initDeque(&dq);

    push_back(&dq, 10);
    push_front(&dq, 20);
    push_back(&dq, 30);

    printDeque(&dq); // 20 10 30

    printf("Front: %d\n", front(&dq)); // 20
    printf("Back: %d\n", back(&dq));   // 30

    printf("Pop front: %d\n", pop_front(&dq)); // 20
    printf("Pop back: %d\n", pop_back(&dq));   // 30

    printDeque(&dq); // 10

    clear(&dq);
    printDeque(&dq); // empty

    return 0;
}
