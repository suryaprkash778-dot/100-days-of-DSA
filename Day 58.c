# Construct a binary tree from given preorder and inorder traversal arrays.

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Find index in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
struct Node* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    // Pick current root
    struct Node* root = createNode(preorder[*preIndex]);
    (*preIndex)++;

    // If single node
    if (start == end)
        return root;

    // Find root in inorder
    int inIndex = search(inorder, start, end, root->data);

    // Build left and right
    root->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int preorder[n], inorder[n];

    printf("Enter preorder:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    printf("Enter inorder:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    printf("Postorder Traversal:\n");
    postorder(root);

    return 0;
}

# Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Create node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Helper function
struct TreeNode* build(int* preorder, int preStart, int preEnd,
                       int* inorder, int inStart, int inEnd,
                       int* map) {

    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    // Root value
    int rootVal = preorder[preStart];
    struct TreeNode* root = createNode(rootVal);

    // Find index in inorder using map
    int inIndex = map[rootVal + 3000];  // offset for negative values

    int leftSize = inIndex - inStart;

    // Build left subtree
    root->left = build(preorder, preStart + 1, preStart + leftSize,
                       inorder, inStart, inIndex - 1, map);

    // Build right subtree
    root->right = build(preorder, preStart + leftSize + 1, preEnd,
                        inorder, inIndex + 1, inEnd, map);

    return root;
}

// Main function
struct TreeNode* buildTree(int* preorder, int preorderSize,
                           int* inorder, int inorderSize) {

    // Map value → index
    int* map = (int*)malloc(6001 * sizeof(int)); // range -3000 to 3000

    for (int i = 0; i < inorderSize; i++) {
        map[inorder[i] + 3000] = i;
    }

    return build(preorder, 0, preorderSize - 1,
                 inorder, 0, inorderSize - 1, map);
}
