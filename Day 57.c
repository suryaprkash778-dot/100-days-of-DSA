# Convert a binary tree into its mirror image by swapping left and right children at every node.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

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

// Build tree (level order)
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);

    struct Node* queue[SIZE];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// 🔥 Mirror Function
void mirror(struct Node* root) {
    if (root == NULL) return;

    // Swap left and right
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recur on subtrees
    mirror(root->left);
    mirror(root->right);
}

// Inorder Traversal
void inorder(struct Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level order (-1 for NULL):\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    // Convert to mirror
    mirror(root);

    // Print inorder of mirrored tree
    printf("Inorder of Mirror Tree:\n");
    inorder(root);

    return 0;
}

# Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void flatten(struct TreeNode* root) {
    struct TreeNode* curr = root;

    while (curr != NULL) {
        if (curr->left != NULL) {

            // Find rightmost of left subtree
            struct TreeNode* temp = curr->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }

            // Attach right subtree
            temp->right = curr->right;

            // Move left subtree to right
            curr->right = curr->left;
            curr->left = NULL;
        }

        // Move to next node
        curr = curr->right;
    }
}
