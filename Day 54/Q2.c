#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Queue implementation
struct Queue {
    struct TreeNode **arr;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->arr = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    return q;
}

bool isEmpty(struct Queue* q) { return q->size == 0; }

void enqueue(struct Queue* q, struct TreeNode* node) {
    if (q->size == q->capacity) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = node;
    q->size++;
}

struct TreeNode* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct TreeNode* item = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

// Zigzag Level Order Traversal
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    struct Queue* q = createQueue(2000);
    enqueue(q, root);

    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));
    *returnSize = 0;

    bool leftToRight = true;

    while (!isEmpty(q)) {
        int levelSize = q->size;
        result[*returnSize] = (int*)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(q);

            // Insert based on direction
            if (leftToRight)
                result[*returnSize][i] = node->val;
            else
                result[*returnSize][levelSize - 1 - i] = node->val;

            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }

        leftToRight = !leftToRight; // flip direction
        (*returnSize)++;
    }

    return result;
}
