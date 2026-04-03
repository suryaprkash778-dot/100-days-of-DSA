// Stack definition
typedef struct Stack {
    int *data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

bool isEmptyStack(Stack* stack) {
    return stack->top == -1;
}

void pushStack(Stack* stack, int x) {
    stack->data[++stack->top] = x;
}

int popStack(Stack* stack) {
    return stack->data[stack->top--];
}

int peekStack(Stack* stack) {
    return stack->data[stack->top];
}

// Queue definition
typedef struct {
    Stack* stackIn;
    Stack* stackOut;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->stackIn = createStack(100);   // capacity fixed for constraints
    queue->stackOut = createStack(100);
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    pushStack(obj->stackIn, x);
}

void transfer(MyQueue* obj) {
    if (isEmptyStack(obj->stackOut)) {
        while (!isEmptyStack(obj->stackIn)) {
            pushStack(obj->stackOut, popStack(obj->stackIn));
        }
    }
}

int myQueuePop(MyQueue* obj) {
    transfer(obj);
    return popStack(obj->stackOut);
}

int myQueuePeek(MyQueue* obj) {
    transfer(obj);
    return peekStack(obj->stackOut);
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmptyStack(obj->stackIn) && isEmptyStack(obj->stackOut);
}

void myQueueFree(MyQueue* obj) {
    free(obj->stackIn->data);
    free(obj->stackOut->data);
    free(obj->stackIn);
    free(obj->stackOut);
    free(obj);
}
