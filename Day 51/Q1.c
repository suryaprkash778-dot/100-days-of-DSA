#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Find node by value
struct TreeNode* findNode(struct TreeNode* root, int val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;
    if (val < root->val) return findNode(root->left, val);
    else return findNode(root->right, val);
}

// Find LCA in BST
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root != NULL) {
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        } else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        } else {
            return root; // Split point found
        }
    }
    return NULL;
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

    // Build BST
    struct TreeNode* root = NULL;
    for (int i = 0; i < N; i++) {
        root = insert(root, arr[i]);
    }

    struct TreeNode* p = findNode(root, pVal);
    struct TreeNode* q = findNode(root, qVal);

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca != NULL) {
        printf("%d\n", lca->val);
    }

    return 0;
}
