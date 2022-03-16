import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb=new StringBuilder();
    static StringTokenizer st;
    static int getInt(){
        return Integer.parseInt(st.nextToken());
    }


    static boolean[][] map;
    public static void main(String[] args) throws Exception {

        int n = Integer.parseInt(br.readLine());
        int k = (int) (Math.log(n/3) / Math.log(2));
        map = new boolean[n][2*n-1];
        draw(0, n - 1, k);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2*n-1; j++) {
                if(map[i][j])
                    sb.append("*");
                else
                    sb.append(" ");
            }
            sb.append("\n");
        }

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

    static void draw(int x,int y,int k){
        if (k == 0) {
            map[x][y] = true;
            map[x+1][y-1] = true;
            map[x+1][y+1] = true;
            for (int i = 0; i < 5; i++) {
                map[x+2][y-2+i] = true;
            }

            return;
        }
        int h = (int) (3*Math.pow(2,k-1));
        int w = 2 * h - 1;
        draw(x,y,k-1);
        draw(x + h, y - (w / 2 + 1), k - 1);
        draw(x + h, y + (w / 2 + 1), k - 1);
    }
}
