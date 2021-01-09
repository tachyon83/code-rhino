class Solution {
    static int x,y;
    static boolean [][] matrix_r;
    static boolean[][] matrix_c;
   
    
    
   
    //row는 0부터 x까지의 값
    //타겟이 행기준 맨 앞과 맨 뒤 사이의 값인지 검사
    static void row(int matrix[][], int row, int target){
        if(matrix[row][0]<= target && matrix[row][y-1]>= target){
            for(int i=0;i<y;i++){
                  matrix_r[row][i] = true;
            }    
        }
    }
    
    
    
    static void col(int matrix[][], int col, int target){
        if(matrix[0][col]<= target && matrix[x-1][col] >= target){
           for(int i=0;i<x;i++){
               matrix_c[i][col] = true;
           }
        }
    }

    
    
     static boolean find(int matrix[][],int target){
        boolean result = false;
        boolean lock=false;
        for(int i=0;i<x;i++){
            if(lock == true){
                break;
            }
            for(int j=0;j<y;j++){
                if(matrix_r[i][j] == true && matrix_c[i][j]==true){
                   //둘다 트루인 경우
                    if(matrix[i][j] == target){
                        result = true;
                        return result;
                       
                    }
                }
                
            }
            
        }
         return result;
    }
    
    

    
    public boolean searchMatrix(int[][] matrix, int target) {
        x = matrix.length;
        y = matrix[0].length;
      
       
        
        matrix_r = new boolean[x][y];
        for(int i=0;i<x;i++){
            row(matrix, i, target);
        }
        
        
        matrix_c = new boolean[x][y];
        for(int i=0;i<y;i++){
            col(matrix, i, target);
        }
        boolean result = find(matrix, target);    
        return result;
    }
    

}
