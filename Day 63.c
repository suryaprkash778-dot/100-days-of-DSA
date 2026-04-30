#include <stdbool.h>

void dfs(int** image, int m, int n, int r, int c, int originalColor, int newColor) {
    // Boundary check
    if (r < 0 || r >= m || c < 0 || c >= n) return;

    // Stop if the pixel is not the original color or already recolored
    if (image[r][c] != originalColor || image[r][c] == newColor) return;

    // Recolor the pixel
    image[r][c] = newColor;

    // Explore neighbors (up, down, left, right)
    dfs(image, m, n, r - 1, c, originalColor, newColor);
    dfs(image, m, n, r + 1, c, originalColor, newColor);
    dfs(image, m, n, r, c - 1, originalColor, newColor);
    dfs(image, m, n, r, c + 1, originalColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int m = imageSize;
    int n = imageColSize[0];   // since all rows have same length

    int originalColor = image[sr][sc];
    if (originalColor != color) {
        dfs(image, m, n, sr, sc, originalColor, color);
    }

    // Prepare return values for LeetCode
    *returnSize = m;
    *returnColumnSizes = imageColSize;
    return image;
}
