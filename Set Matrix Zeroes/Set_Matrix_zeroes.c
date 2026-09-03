#include <stdio.h>
#include <stdlib.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    int columns = *matrixColSize;

    int* rowZero = (int*)calloc(rows, sizeof(int));
    int* colZero = (int*)calloc(columns, sizeof(int));

    // First pass: mark rows and columns
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(matrix[i][j]==0){
                rowZero[i] = 1;
                colZero[j] = 1;
            }
        }
    }

    // Second pass: set zeros
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(rowZero[i] || colZero[j]){
                matrix[i][j] = 0;
            }
        }
    }

    free(rowZero);
    free(colZero);
}
