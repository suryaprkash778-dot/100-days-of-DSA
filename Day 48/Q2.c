#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Utility function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper function to check if a node is a leaf
int isLeaf(struct TreeNode* node) {
    return (node != NULL && node->left == NULL && node->right == NULL);
}

// Recursive function to calculate sum of left leaves
int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL) return 0;

    int sum = 0;

    // Check if left child is a leaf
    if (isLeaf(root->left)) {
        sum += root->left->val;
    } else {
        sum += sumOfLeftLeaves(root->left);
    }

    // Recurse on right subtree
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

// Example usage
int main() {
    /*
        Example Tree:
              3
             / \
            9  20
               / \
              15  7

        Left leaves: 9 and 15 → Sum = 24
    */

    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("Sum of Left Leaves: %d\n", sumOfLeftLeaves(root));

    return 0;
}
