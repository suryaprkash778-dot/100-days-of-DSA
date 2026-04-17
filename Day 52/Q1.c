#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Queue structure for building tree from level order
struct Queue {
    struct TreeNode** arr;
    int front, rear, size;
};

// Create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Initialize queue
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * size);
    q->front = 0;
    q->rear = 0;
    q->size = size;
    return q;
}

// Enqueue
void enqueue(struct Queue* q, struct TreeNode* node) {
    q->arr[q->rear++] = node;
}

// Dequeue
struct TreeNode* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Build tree from level order input
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;
    while (i < n) {
        struct TreeNode* parent = dequeue(q);

        // Left child
        if (arr[i] != -1) {
            parent->left = newNode(arr[i]);
            enqueue(q, parent->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            parent->right = newNode(arr[i]);
            enqueue(q, parent->right);
        }
        i++;
    }
    return root;
}

// Find LCA in binary tree
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || root == p || root == q) return root;

    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) return root;
    return left ? left : right;
}

// Find node by value
struct TreeNode* findNode(struct TreeNode* root, int val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;
    struct TreeNode* left = findNode(root->left, val);
    if (left) return left;
    return findNode(root->right, val);
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int pVal, qVal;
    scanf("%d %d", &pVal, &qVal);

    struct TreeNode* root = buildTree(arr, N);
    struct TreeNode* p = findNode(root, pVal);
    struct TreeNode* q = findNode(root, qVal);

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca) {
        printf("%d\n", lca->val);
    }

    return 0;
}
