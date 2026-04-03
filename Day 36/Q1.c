#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Circular Queue structure
typedef struct {
    Node* front;
    Node* rear;
} CircularQueue;

// Initialize queue
void initQueue(CircularQueue* q) {
    q->front = q->rear = NULL;
}

// Enqueue operation
void enqueue(CircularQueue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        newNode->next = newNode; // circular link
    } else {
        newNode->next = q->front;
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Dequeue operation
int dequeue(CircularQueue* q) {
    if (q->front == NULL) {
        return -1; // empty
    }
    int value = q->front->data;
    if (q->front == q->rear) {
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        Node* temp = q->front;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }
    return value;
}

// Display queue elements
void displayQueue(CircularQueue* q) {
    if (q->front == NULL) return;
    Node* current = q->front;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != q->front);
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d", &n);

    CircularQueue q;
    initQueue(&q);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    scanf("%d", &m);

    // Perform m dequeues and enqueue back (rotation)
    for (int i = 0; i < m; i++) {
        int val = dequeue(&q);
        if (val != -1) {
            enqueue(&q, val);
        }
    }

    displayQueue(&q);

    return 0;
}
