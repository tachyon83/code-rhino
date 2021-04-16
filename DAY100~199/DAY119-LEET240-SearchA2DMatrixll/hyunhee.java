// import java.util.Arrays;
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        boolean flag = false;
        for(int[] m : matrix){
            int answer = Arrays.binarySearch(m, target);
            if(answer>=0){
                flag = true;
                break;
            }
        }
        return flag;
        
    }
}