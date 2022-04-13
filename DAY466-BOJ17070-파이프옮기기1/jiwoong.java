package submit;

import java.io.*;
import java.util.*;



public class jiwoong{
    static int n;
    static int count = 0;
    static int[][] map;
    public static void main(String []args) throws Exception{
        BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());

        map = new int[n+1][n+1];
        for(int i=1;i<=n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1;j<=n;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        DFS(1,2,0);
        bw.write(count+"");
        bw.flush();
        bw.close();
    }
    static void DFS(int x,int y, int shape){
        if(x== n&& y==n){
            count++;
            return;
        }
        if(shape ==0){
            if(y+1<=n && map[x][y+1]==0) DFS(x,y+1,0);
            if(y+1<=n && x+1<=n &&map[x][y + 1] == 0 && map[x + 1][y] == 0 && map[x+1][y+1]==0) DFS(x+1,y+1,2);
        } else if(shape == 1){
            if(x+1<=n && map[x+1][y]==0) DFS(x+1,y,1);
            if(y+1<=n && x+1<=n &&map[x][y + 1] == 0 && map[x + 1][y] == 0 && map[x+1][y+1]==0) DFS(x+1,y+1,2);
        } else if(shape ==2){
            if(y+1<=n && map[x][y+1]==0) DFS(x,y+1,0);
            if(x+1<=n && map[x+1][y]==0) DFS(x+1,y,1);
            if(y+1<=n && x+1<=n &&map[x][y + 1] == 0 && map[x + 1][y] == 0 && map[x+1][y+1]==0) DFS(x+1,y+1,2);
        }
    }

}