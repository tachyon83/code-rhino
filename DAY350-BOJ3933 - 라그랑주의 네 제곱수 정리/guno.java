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


    public static void main(String[] args) throws Exception {
        int MAX = 1 << 15;
        int[][] dp = new int[5][MAX]; // dp[i][j] i개의 제곱수의 합으로 j를 만들수 있는 수

        for (int i = 1; i * i < MAX; i++) {
            int ii = i * i;
            dp[1][ii] = 1;

            for (int j = ii; j < MAX; j++) {
                dp[2][j] += dp[1][j - ii];
                dp[3][j] += dp[2][j - ii];
                dp[4][j] += dp[3][j - ii];
            }
        }

        while (true) {
            int n = Integer.parseInt(br.readLine());
            if(n==0)
                break;

            int ans = 0;
            for (int i = 1; i < 5; i++) {
                ans += dp[i][n];
            }
            sb.append(ans).append("\n");
        }



        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
