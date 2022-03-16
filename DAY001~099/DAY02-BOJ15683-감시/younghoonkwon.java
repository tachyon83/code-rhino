import java.util.*;

public class Main
{
    static int N;
    static int M;
    static int[][] grid;
    static int count = 0;
    static int[] camRow = new int[8];
    static int[] camCol = new int[8];
    static int[] camNum = new int[8];
    static int min_sum = 9999;
    static int dx[] = {-1, 0, 1, 0}; //left up right down
    static int dy[] = {0, 1, 0, -1};
    
	public static void main(String[] args) {
	    init();
		dfs(0);
		System.out.println(min_sum);
	}
	public static void init(){
	    Scanner scan = new Scanner(System.in);
		N = scan.nextInt();
		M = scan.nextInt();
		grid = new int[N][M];
		for(int i = 0; i < N; i++){
		    for (int j = 0; j < M; j++){
		        grid[i][j] = scan.nextInt();
		        if(grid[i][j] >= 1 && grid[i][j] <= 5){
		            camRow[count] = i;
		            camCol[count] = j;
		            camNum[count] = grid[i][j];
		            count++;
		        }
		    }
		}
	}
	public static void dfs(int pos){
	    //base case, finish searching
	    if(pos == count){
	        int sum = 0;
	        for(int i = 0; i < N; i++){
	            for(int j = 0; j < M; j++){
	                if(grid[i][j] == 0){
	                    sum += 1;
	                }
	            }
	        }
	        min_sum = Math.min(sum, min_sum);
	       // printGrid(grid);
	        return;
	    }
	    else{
	        int gridCopy[][] = new int[N][M];
	       // 1st camera
	        if(camNum[pos] == 1){
	            for(int i = 0; i < 4; i++){
	                gridCopy(grid, gridCopy);
	                step(camRow[pos], camCol[pos], i);
	                dfs(pos+1);
	                gridCopy(gridCopy, grid);
	            }
	        }
	       // 2nd camera
	        else if(camNum[pos] == 2){
	            for(int i = 0; i < 2; i++){
	                gridCopy(grid, gridCopy);
	                step(camRow[pos], camCol[pos], i);
	                step(camRow[pos], camCol[pos], (i+2)%4);
	                dfs(pos+1);
	                gridCopy(gridCopy, grid);
	            }
	            
	        }
	       // 3rd camera
	        else if(camNum[pos] == 3){
	            for(int i = 0; i < 4; i++){
                    gridCopy(grid, gridCopy);
	                step(camRow[pos], camCol[pos], i);
	                step(camRow[pos], camCol[pos], (i+1)%4);
	                dfs(pos+1);
	                gridCopy(gridCopy, grid);
	            }
	        }
	       // 4th camera
	        else if(camNum[pos] == 4){
	            for(int i = 0; i < 4; i++){
	                gridCopy(grid, gridCopy);
	                step(camRow[pos], camCol[pos], i);
	                step(camRow[pos], camCol[pos], (i+1)%4);
	                step(camRow[pos], camCol[pos], (i+2)%4);
	                dfs(pos+1);
	                gridCopy(gridCopy, grid);
	            }
	        }
	        // 5th camera
	        else{
	            gridCopy(grid, gridCopy);
	            for(int i = 0; i < 4; i++){
	                step(camRow[pos], camCol[pos], i);
	            }
                dfs(pos+1);
                gridCopy(gridCopy, grid);
	        }
	    }
	}
    public static boolean is_available(int x, int y) {
        if( x >= 0 && y >= 0 && x < N && y < M && grid[x][y] != 6) {
            return true;
        }
        else{
            return false;
        }
    }
    
    public static void step(int x, int y, int dir){
        x += dx[dir];
        y += dy[dir];
        while(is_available(x, y)) {
            // System.out.println("stepping x,y :  " + x + "," + y);
            grid[x][y] = 7;
            x += dx[dir];
            y += dy[dir];
        }
    }
    
    public static void gridCopy(int[][] grid, int[][] gridCopy){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                gridCopy[i][j] = grid[i][j];
            }
        }
    }
    
    public static void printGrid(int[][] grid){
        for(int i = 0; i < N; i++){
            System.out.println();
            for(int j = 0; j < M; j++){
                System.out.print(grid[i][j]);
            }
        }
        System.out.println();
    }
}
