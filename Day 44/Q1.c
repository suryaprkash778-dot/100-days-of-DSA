#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Queue structure for building the tree
struct Queue {
    struct TreeNode** arr;
    int front, rear, size;
};

struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * size);
    q->front = 0;
    q->rear = 0;
    q->size = size;
    return q;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->arr[q->rear++] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Build tree from level-order input
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = arr[0];
    root->left = root->right = NULL;

    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;
    while (i < n && !isEmpty(q)) {
        struct TreeNode* curr = dequeue(q);

        // Left child
        if (arr[i] != -1) {
            curr->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            curr->left->val = arr[i];
            curr->left->left = curr->left->right = NULL;
            enqueue(q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            curr->right->val = arr[i];
            curr->right->left = curr->right->right = NULL;
            enqueue(q, curr->right);
        }
        i++;
    }

    return root;
}

// Traversals
void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void preorder(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, N);

    // Print traversals
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    return 0;
}
