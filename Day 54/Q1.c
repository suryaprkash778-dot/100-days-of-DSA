#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of a binary tree node
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

// Build tree from level order input
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct TreeNode** nodes = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) nodes[i] = NULL;
        else {
            nodes[i] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            nodes[i]->val = arr[i];
            nodes[i]->left = nodes[i]->right = NULL;
        }
    }
    for (int i = 0; i < n; i++) {
        if (nodes[i]) {
            int leftIndex = 2*i + 1;
            int rightIndex = 2*i + 2;
            if (leftIndex < n) nodes[i]->left = nodes[leftIndex];
            if (rightIndex < n) nodes[i]->right = nodes[rightIndex];
        }
    }
    return nodes[0];
}

// Zigzag Traversal
void zigzagTraversal(struct TreeNode* root) {
    if (!root) return;

    struct Queue* q = createQueue(2000);
    enqueue(q, root);

    bool leftToRight = true;

    while (!isEmpty(q)) {
        int levelSize = q->size;
        int* level = (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(q);

            if (leftToRight)
                level[i] = node->val;
            else
                level[levelSize - 1 - i] = node->val;

            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }

        for (int i = 0; i < levelSize; i++) {
            printf("%d ", level[i]);
        }
        free(level);

        leftToRight = !leftToRight; // flip direction
    }
}

// Driver
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);
    zigzagTraversal(root);

    return 0;
}
