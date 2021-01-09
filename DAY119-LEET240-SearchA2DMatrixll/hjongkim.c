bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int i = matrixSize - 1;
    int j = 0;
    
    while (i >= 0 && j < *matrixColSize) {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] < target)
            j++;
        else
            i--;
    }
    return false;
}
