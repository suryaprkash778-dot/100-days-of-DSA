#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
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

// Function to find LCA in BST
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root != NULL) {
        if (p->val < root->val && q->val < root->val) {
            root = root->left;  // Both nodes are in the left subtree
        } else if (p->val > root->val && q->val > root->val) {
            root = root->right; // Both nodes are in the right subtree
        } else {
            return root; // Found the split point, this is the LCA
        }
    }
    return NULL;
}

// Example usage
int main() {
    // Constructing the BST from Example 1
    struct TreeNode* root = newNode(6);
    root->left = newNode(2);
    root->right = newNode(8);
    root->left->left = newNode(0);
    root->left->right = newNode(4);
    root->right->left = newNode(7);
    root->right->right = newNode(9);
    root->left->right->left = newNode(3);
    root->left->right->right = newNode(5);

    struct TreeNode* p = root->left;       // Node with value 2
    struct TreeNode* q = root->right;      // Node with value 8

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);
    printf("LCA of %d and %d is %d\n", p->val, q->val, lca->val);

    return 0;
}
