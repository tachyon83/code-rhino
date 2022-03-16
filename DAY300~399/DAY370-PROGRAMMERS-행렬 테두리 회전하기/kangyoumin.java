class Solution {
    public int[] solution(int rows, int columns, int[][] queries) {
        int[][] nums = new int[rows][columns];
        int num = 1;
        for(int i=0 ; i<rows ; i++) {
            for(int j=0 ; j<columns ; j++) {
                nums[i][j] = num++;
            }
        }
        int[] ret = new int[queries.length];
        for(int i=0 ; i<queries.length ; i++) {
            int[] query = queries[i];
            int r1=query[0]-1, c1=query[1]-1, r2=query[2]-1, c2=query[3]-1;
            int tmp = nums[r1][c1];
            int min = tmp;
            
            for(int r=r1+1 ; r<=r2 ; r++) {
                min = Math.min(min, nums[r][c1]);
                nums[r-1][c1] = nums[r][c1];
            }
            for(int c=c1+1 ; c<=c2 ; c++) {
                min = Math.min(min, nums[r2][c]);
                nums[r2][c-1] = nums[r2][c];
            }
            for(int r=r2-1 ; r>=r1 ; r--) {
                min = Math.min(min, nums[r][c2]);
                nums[r+1][c2] = nums[r][c2];
            }
            for(int c=c2-1 ; c>c1 ; c--) {
                min = Math.min(min, nums[r1][c]);
                nums[r1][c+1] = nums[r1][c];
            }
            nums[r1][c1+1] = tmp;
            ret[i] = min;
        }
        return ret;
    }
}
