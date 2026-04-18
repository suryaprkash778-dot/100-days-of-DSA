#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definition of a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Queue node for BFS
struct QNode {
    struct TreeNode *node;
    int hd; // horizontal distance
};

// Simple queue implementation
struct Queue {
    struct QNode *arr;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->arr = (struct QNode*)malloc(capacity * sizeof(struct QNode));
    return q;
}

int isEmpty(struct Queue* q) { return q->size == 0; }

void enqueue(struct Queue* q, struct TreeNode* node, int hd) {
    if (q->size == q->capacity) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
    q->size++;
}

struct QNode dequeue(struct Queue* q) {
    struct QNode item = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

// Map structure for storing vertical lines
struct List {
    int *vals;
    int size;
    int capacity;
};

struct List* createList(int capacity) {
    struct List* l = (struct List*)malloc(sizeof(struct List));
    l->vals = (int*)malloc(capacity * sizeof(int));
    l->size = 0;
    l->capacity = capacity;
    return l;
}

void addToList(struct List* l, int val) {
    if (l->size == l->capacity) {
        l->capacity *= 2;
        l->vals = (int*)realloc(l->vals, l->capacity * sizeof(int));
    }
    l->vals[l->size++] = val;
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

// Vertical Order Traversal
void verticalOrder(struct TreeNode* root) {
    if (!root) return;

    struct Queue* q = createQueue(2000);
    enqueue(q, root, 0);

    // Map HD -> list of nodes
    struct List* map[4001]; // offset for negative HD
    for (int i = 0; i < 4001; i++) map[i] = createList(10);

    int minHD = INT_MAX, maxHD = INT_MIN;

    while (!isEmpty(q)) {
        struct QNode qn = dequeue(q);
        struct TreeNode* node = qn.node;
        int hd = qn.hd;

        addToList(map[hd + 2000], node->val);

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left) enqueue(q, node->left, hd - 1);
        if (node->right) enqueue(q, node->right, hd + 1);
    }

    // Print vertical order
    for (int hd = minHD; hd <= maxHD; hd++) {
        struct List* l = map[hd + 2000];
        for (int i = 0; i < l->size; i++) {
            printf("%d ", l->vals[i]);
        }
        printf("\n");
    }
}

// Driver
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);
    verticalOrder(root);

    return 0;
}
