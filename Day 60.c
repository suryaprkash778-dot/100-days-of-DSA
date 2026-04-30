# Check whether a given binary tree satisfies the Min-Heap property.

#include <stdio.h>

// Function to check Min Heap
int isMinHeap(int arr[], int n) {
    int i;

    // Check only parent nodes
    for (i = 0; i <= (n - 2) / 2; i++) {

        // Left child check
        if (2*i + 1 < n && arr[i] > arr[2*i + 1])
            return 0;

        // Right child check
        if (2*i + 2 < n && arr[i] > arr[2*i + 2])
            return 0;
    }

    return 1;
}

int main() {
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements in level order: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, n))
        printf("YES (It is a Min Heap)");
    else
        printf("NO (Not a Min Heap)");

    return 0;
}

# You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

int cameras = 0;

// Function to decide camera placement
int solve(struct TreeNode* root) {
    if (root == NULL)
        return 0; // Covered

    int left = solve(root->left);
    int right = solve(root->right);

    // If any child is NOT covered
    if (left == -1 || right == -1) {
        cameras++;
        return 1; // Has camera
    }

    // If any child has camera
    if (left == 1 || right == 1)
        return 0; // Covered

    return -1; // Not covered
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0; // reset for safety

    if (solve(root) == -1)
        cameras++;

    return cameras;
}
