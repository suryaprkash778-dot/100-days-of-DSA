#define MAX 10000   // maximum stack size

typedef struct {
    int data[MAX];      // main stack
    int minData[MAX];   // stack to track minimums
    int top;            // pointer for main stack
    int minTop;         // pointer for min stack
} MinStack;

// Initialize MinStack
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top = -1;
    obj->minTop = -1;
    return obj;
}

// Push operation
void minStackPush(MinStack* obj, int val) {
    obj->data[++obj->top] = val;
    if (obj->minTop == -1 || val <= obj->minData[obj->minTop]) {
        obj->minData[++obj->minTop] = val;
    }
}

// Pop operation
void minStackPop(MinStack* obj) {
    if (obj->top == -1) return;
    int popped = obj->data[obj->top--];
    if (popped == obj->minData[obj->minTop]) {
        obj->minTop--;
    }
}

// Top operation
int minStackTop(MinStack* obj) {
    if (obj->top == -1) return INT_MIN; // stack empty
    return obj->data[obj->top];
}

// GetMin operation
int minStackGetMin(MinStack* obj) {
    if (obj->minTop == -1) return INT_MIN; // stack empty
    return obj->minData[obj->minTop];
}

// Free memory
void minStackFree(MinStack* obj) {
    free(obj);
}

