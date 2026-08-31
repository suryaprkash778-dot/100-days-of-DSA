int* left_to_right(int** matrix, int* new_matrix,int row_num, int end_index,int new_start_index,int start_index){
    for(int i=start_index;i<=end_index,i++){
        new_matrix[new_start_index]=matrix[row_num][i];
    }
    return new_matrix;
}

int* right_to_leftt(int** matrix, int* new_matrix,int row_num, int end_index,int new_start_index,int start_index){
    for(int i=start_index;i>=end_index,i--){
        new_matrix[new_start_index]=matrix[row_num][i];
    }
    return new_matrix;
}

int* up_to_down(int** matrix, int* new_matrix,int row_num, int end_index,int new_start_index,int start_index){
    for(int i=start_index;i>=end_index,i--){
        new_matrix[new_start_index]=matrix[row_num][i];
    }
    return new_matrix;
}

int* down_to_up(int** matrix, int* new_matrix,int row_num, int end_index,int new_start_index,int start_index){
    for(int i=start_index;i>=end_index,i--){
        new_matrix[new_start_index]=matrix[row_num][i];
    }
    return new_matrix;
}
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {

      
}

