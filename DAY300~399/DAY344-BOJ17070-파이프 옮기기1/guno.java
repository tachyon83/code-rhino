import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb=new StringBuilder();
    static StringTokenizer st;

    static int n;
    static boolean[][] isWall;
    static int[][] dp1;
    static int[][] dp2;
    static int[][] dp3;
    public static void main(String[] args) throws Exception {

        n = Integer.parseInt(br.readLine());
        isWall = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                int num = Integer.parseInt(st.nextToken());
                if(num==1)
                    isWall[i][j] = true;
            }
        }

        dp1 = new int[n][n];
        dp2 = new int[n][n];
        dp3 = new int[n][n];
        dp1[0][1] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visit(i,j);
            }
        }

        sb.append(dp1[n-1][n-1]+dp2[n-1][n-1]+dp3[n-1][n-1]);

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

    static void visit(int x,int y){
        int right = dp1[x][y], down = dp2[x][y], diag = dp3[x][y];
        moveRight(x,y,right+diag);
        moveDown(x,y,down+diag);
        moveDiag(x,y,right+down+diag);
    }

    static void moveRight(int x,int y,int num){
        if(y<n-1 && !isWall[x][y+1])
            dp1[x][y+1]+=num;
    }
    static void moveDown(int x,int y,int num){
        if(x<n-1 && !isWall[x+1][y])
            dp2[x+1][y]+=num;
    }
    static void moveDiag(int x,int y,int num){
        if(x<n-1 && y<n-1 && !isWall[x][y+1] && !isWall[x+1][y] && !isWall[x+1][y+1])
            dp3[x+1][y+1]+=num;
    }

}
