#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to search in BST
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;
    if (val < root->val) return searchBST(root->left, val);
    else return searchBST(root->right, val);
}

// Helper function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Inorder traversal to print subtree
void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Example usage
int main() {
    // Construct BST: [4,2,7,1,3]
    struct TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(7);
    root->left->left = createNode(1);
    root->left->right = createNode(3);

    int val = 2;
    struct TreeNode* result = searchBST(root, val);

    if (result != NULL) {
        printf("Subtree rooted at %d: ", val);
        inorder(result);
    } else {
        printf("Value %d not found in BST.", val);
    }

    return 0;
}
