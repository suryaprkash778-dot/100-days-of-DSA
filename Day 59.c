# Construct a binary tree from given inorder and postorder traversal arrays.

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

// Search in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
struct Node* buildTree(int inorder[], int postorder[],
                       int start, int end, int* postIndex) {

    if (start > end)
        return NULL;

    // Pick root from postorder
    struct Node* root = createNode(postorder[*postIndex]);
    (*postIndex)--;

    // If single node
    if (start == end)
        return root;

    int inIndex = search(inorder, start, end, root->data);

    // ⚠️ Build right first
    root->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    root->left  = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Main
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int inorder[n], postorder[n];

    printf("Enter inorder:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    printf("Enter postorder:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Preorder Traversal:\n");
    preorder(root);

    return 0;
}

# Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

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
struct TreeNode* build(int* inorder, int inStart, int inEnd,
                       int* postorder, int* postIndex,
                       int* map) {

    if (inStart > inEnd)
        return NULL;

    // Root from postorder
    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = createNode(rootVal);

    // Find index in inorder
    int inIndex = map[rootVal + 3000];

    // 🔥 Build right first
    root->right = build(inorder, inIndex + 1, inEnd,
                        postorder, postIndex, map);

    root->left = build(inorder, inStart, inIndex - 1,
                       postorder, postIndex, map);

    return root;
}

// Main function
struct TreeNode* buildTree(int* inorder, int inorderSize,
                           int* postorder, int postorderSize) {

    // Map value → index
    int* map = (int*)malloc(6001 * sizeof(int));

    for (int i = 0; i < inorderSize; i++) {
        map[inorder[i] + 3000] = i;
    }

    int postIndex = postorderSize - 1;

    return build(inorder, 0, inorderSize - 1,
                 postorder, &postIndex, map);
}
