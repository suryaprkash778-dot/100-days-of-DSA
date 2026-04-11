#include <stdio.h>
#include <stdlib.h>

// Definition of tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create a new node
struct TreeNode* newNode(int val) {
    if (val == -1) return NULL;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level-order input
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = newNode(arr[0]);
    struct TreeNode** queue = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct TreeNode* curr = queue[front++];
        if (curr != NULL) {
            // Left child
            curr->left = newNode(arr[i++]);
            if (curr->left) queue[rear++] = curr->left;

            if (i < n) {
                // Right child
                curr->right = newNode(arr[i++]);
                if (curr->right) queue[rear++] = curr->right;
            }
        }
    }
    free(queue);
    return root;
}

// Perform level order traversal
void levelOrder(struct TreeNode* root) {
    if (root == NULL) {
        printf("[]\n");
        return;
    }

    struct TreeNode** queue = (struct TreeNode**)malloc(2000 * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    printf("[");
    while (front < rear) {
        int levelSize = rear - front;
        printf("[");
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            printf("%d", node->val);
            if (i < levelSize - 1) printf(",");
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        printf("]");
        if (front < rear) printf(",");
    }
    printf("]\n");

    free(queue);
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, N);
    levelOrder(root);

    return 0;
}
