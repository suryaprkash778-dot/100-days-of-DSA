int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int rows = matrixSize;
    int cols = *matrixColSize;
    *returnSize = rows * cols;
    int* result = (int*)malloc((*returnSize) * sizeof(int));

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int idx = 0;

    while (top <= bottom && left <= right) {
        // left to right
        for (int j = left; j <= right; j++)
            result[idx++] = matrix[top][j];
        top++;

        // top to bottom
        for (int i = top; i <= bottom; i++)
            result[idx++] = matrix[i][right];
        right--;

        // right to left
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                result[idx++] = matrix[bottom][j];
            bottom--;
        }

        // bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[idx++] = matrix[i][left];
            left++;
        }
    }

    return result;
}
