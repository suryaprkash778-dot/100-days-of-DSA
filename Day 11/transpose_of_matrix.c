int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    
    int row_size = matrixSize - *matrixColSize;
    int** m2[*matrixColSize][row_size];


    
   for(int i=0;i<row_size;i++){
    for(int j=0;j<*matrixColSize;j++){
        int temp = matrix[i][j];
        matrix[i][j]=matrix[j][i];
        matrix[j][i]=temp;
    }
   }
   return matrix;
}

