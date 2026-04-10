/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Recursive helper function for preorder traversal.
 */
void preorder(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) return;

    // Visit current node first
    result[(*returnSize)++] = root->val;

    // Then traverse left subtree
    preorder(root->left, result, returnSize);

    // Finally traverse right subtree
    preorder(root->right, result, returnSize);
}

/**
 * Main function called by LeetCode.
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    // Allocate space for result (max 100 nodes as per constraints)
    int* result = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;

    preorder(root, result, returnSize);

    return result;
}
