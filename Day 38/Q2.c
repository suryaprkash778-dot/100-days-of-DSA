// Deque structure
typedef struct {
    int *data;
    int front, rear, size;
} Deque;

Deque* createDeque(int n) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->data = (int*)malloc(sizeof(int) * n);
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
    return dq;
}

int isEmpty(Deque* dq) {
    return dq->size == 0;
}

void pushBack(Deque* dq, int val) {
    dq->data[++dq->rear] = val;
    dq->size++;
}

void popBack(Deque* dq) {
    dq->rear--;
    dq->size--;
}

void popFront(Deque* dq) {
    dq->front++;
    dq->size--;
}

int front(Deque* dq) {
    return dq->data[dq->front];
}

int back(Deque* dq) {
    return dq->data[dq->rear];
}

// Sliding Window Maximum
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    *returnSize = 0;

    Deque* dq = createDeque(numsSize);

    for (int i = 0; i < numsSize; i++) {
        // Remove indices out of current window
        if (!isEmpty(dq) && front(dq) <= i - k) {
            popFront(dq);
        }

        // Remove smaller elements from the back
        while (!isEmpty(dq) && nums[back(dq)] <= nums[i]) {
            popBack(dq);
        }

        // Add current index
        pushBack(dq, i);

        // Record max for window
        if (i >= k - 1) {
            result[*returnSize] = nums[front(dq)];
            (*returnSize)++;
        }
    }

    free(dq->data);
    free(dq);
    return result;
}

