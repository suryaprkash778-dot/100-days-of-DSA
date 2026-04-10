/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Helper function to perform inorder traversal.
 */
void inorder(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) return;

    // Traverse left subtree
    inorder(root->left, result, returnSize);

    // Visit current node
    result[(*returnSize)++] = root->val;

    // Traverse right subtree
    inorder(root->right, result, returnSize);
}

/**
 * Main function called by LeetCode.
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // Allocate space for result (max 100 nodes as per constraints)
    int* result = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;

    inorder(root, result, returnSize);

    return result;
}
