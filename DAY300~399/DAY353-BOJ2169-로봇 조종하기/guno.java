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

    static int n,m;
    static int[][] dpLeft;
    static int[][] dpRight;
    static int[][] map;

    public static void main(String[] args) throws Exception {

        st = new StringTokenizer(br.readLine());
        n = getInt(); m = getInt();
        map = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = getInt();
            }
        }
        dpLeft = new int[n][m];
        dpRight = new int[n][m];
        int[][] dp = new int[n][m];

        dp[0][0] = map[0][0];
        for (int i = 1; i < m; i++) {
            dp[0][i] = dp[0][i - 1] + map[0][i];
        }

        for (int i = 1; i < n; i++) {
            dpRight[i][0] = dp[i - 1][0] + map[i][0];
            dpLeft[i][m-1] = dp[i - 1][m-1] + map[i][m-1];
            for (int j = 1; j < m; j++) {
                dpRight[i][j] = Math.max(dpRight[i][j - 1], dp[i - 1][j]) + map[i][j];
            }
            for (int j = m-2; j >=0 ; j--) {
                dpLeft[i][j] = Math.max(dpLeft[i][j + 1], dp[i - 1][j]) + map[i][j];
            }
            for (int j = 0; j < m; j++) {
                dp[i][j] = Math.max(dpLeft[i][j], dpRight[i][j]);
            }
        }
        sb.append(dp[n - 1][m - 1]);

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
