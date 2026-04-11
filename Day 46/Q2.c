/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Return an array of arrays of integers.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * The number of arrays is returned as *returnSize.
 * Note: The returned array must be malloc'ed, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (root == NULL) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Allocate space for results
    int capacity = 2000; // max nodes
    int** result = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);

    // Queue for BFS
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * capacity);
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        result[*returnSize] = (int*)malloc(sizeof(int) * levelSize);
        (*returnColumnSizes)[*returnSize] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            result[*returnSize][i] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        (*returnSize)++;
    }

    free(queue);
    return result;
}
