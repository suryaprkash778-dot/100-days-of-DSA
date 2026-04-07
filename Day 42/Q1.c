#include <stdio.h>
#include <stdlib.h>

// Queue implementation using linked list
struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) return -1;
    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return val;
}

int isEmptyQueue(struct Queue* q) {
    return q->front == NULL;
}

// Stack implementation using linked list
struct Stack {
    struct Node* top;
};

void initStack(struct Stack* s) {
    s->top = NULL;
}

void push(struct Stack* s, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(struct Stack* s) {
    if (s->top == NULL) return -1;
    struct Node* temp = s->top;
    int val = temp->data;
    s->top = s->top->next;
    free(temp);
    return val;
}

int isEmptyStack(struct Stack* s) {
    return s->top == NULL;
}

int main() {
    int N;
    scanf("%d", &N);

    struct Queue q;
    initQueue(&q);

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    // Reverse using stack
    struct Stack s;
    initStack(&s);

    while (!isEmptyQueue(&q)) {
        push(&s, dequeue(&q));
    }

    while (!isEmptyStack(&s)) {
        printf("%d ", pop(&s));
    }

    return 0;
}
