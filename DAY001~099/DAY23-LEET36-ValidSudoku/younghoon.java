class Solution {
    public boolean isValidSudoku(char[][] board) {
        
        boolean ans1 = checkRow(board);
        if(ans1 == false){
            return false;
        }
        System.out.println("row ok");
        boolean ans2 = checkColumn(board);
        if(ans2 == false){
            return false;
        }
        System.out.println("col ok");
        boolean ans3 = checkBoxes(board);
        if(ans3 == false){
            return false;
        }
        return true;
    }
    public boolean checkRow(char[][] board){
        
        for(int i = 0; i < 9; i++){
            HashMap<Character, Integer> map = new HashMap<>();
            for(int j = 0; j < 9; j++){
                if(map.containsKey(board[i][j])){
                    return false;
                }
                if(board[i][j] != '.'){
                    map.put(board[i][j] , 1);
                }
                
            }    
        }
        return true;
    }
    public boolean checkColumn(char[][] board){
        for(int i = 0; i < 9; i++){
            HashMap<Character, Integer> map = new HashMap<>();
            for(int j = 0; j < 9; j++){
                if(map.containsKey(board[j][i])){
                    return false;
                }
                if(board[j][i] != '.'){
                    map.put(board[j][i] , 1);
                }
                
            }    
        }
        return true;
    }
    public boolean checkBoxes(char[][] board){
        for(int i = 0; i < 9; i = i + 3){
            for(int j = 0; j < 9; j = j + 3){
                if(checkSingleBox(board, i, j) == false){
                    return false;
                }
            }
        }
        return true;
    }
    public boolean checkSingleBox(char[][] board, int x, int y){
        HashMap<Character, Integer> map = new HashMap<>();
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(map.containsKey(board[x+i][y+j])){
                    return false;
                }
                if(Character.isDigit(board[x+i][y+j])){
                    map.put(board[x+i][y+j] , 1);
                }
            }
        }
        return true;
    }
}
