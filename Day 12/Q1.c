#include <stdio.h>

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    // Read matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if square
    if (m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }

    // Check symmetry
    int symmetric = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if (!symmetric) break;
    }

    if (symmetric)
        printf("Symmetric Matrix\n");
    else
        printf("Not a Symmetric Matrix\n");

    return 0;
}
