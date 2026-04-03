typedef struct {
    int *data;
    int front;
    int rear;
    int size;
    int count;
} MyCircularDeque;

/** Initialize your data structure here. */
MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->data = (int*)malloc(sizeof(int) * k);
    obj->size = k;
    obj->front = 0;
    obj->rear = -1;
    obj->count = 0;
    return obj;
}

/** Adds an item at the front of Deque. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->count == obj->size) return false; // full
    obj->front = (obj->front - 1 + obj->size) % obj->size;
    obj->data[obj->front] = value;
    obj->count++;
    if (obj->count == 1) obj->rear = obj->front;
    return true;
}

/** Adds an item at the rear of Deque. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->count == obj->size) return false; // full
    obj->rear = (obj->rear + 1) % obj->size;
    obj->data[obj->rear] = value;
    obj->count++;
    if (obj->count == 1) obj->front = obj->rear;
    return true;
}

/** Deletes an item from the front of Deque. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->count == 0) return false; // empty
    obj->front = (obj->front + 1) % obj->size;
    obj->count--;
    return true;
}

/** Deletes an item from the rear of Deque. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->count == 0) return false; // empty
    obj->rear = (obj->rear - 1 + obj->size) % obj->size;
    obj->count--;
    return true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->count == 0) return -1;
    return obj->data[obj->front];
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->count == 0) return -1;
    return obj->data[obj->rear];
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->count == 0;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->count == obj->size;
}

/** Free memory */
void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->data);
    free(obj);
}
