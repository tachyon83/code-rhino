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
    static void getSt() throws IOException {st = new StringTokenizer(br.readLine());}

    public static void main(String[] args) throws Exception {

        getSt();
        int n = getInt();
        getSt();
        int k = getInt();
        int MOD = 1000000003;
        int[][] dp=new int[1002][1002];
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        dp[1][1] = 1;
        for (int i = 2; i < n; i++) {
            for (int j = 1; j <= (i+1) / 2; j++) {
                dp[i][j] = dp[i - 2][j - 1] + dp[i - 1][j];
                dp[i][j] %= MOD;
            }
        }

        sb.append((dp[n - 1][k] + dp[n - 3][k - 1]) % MOD);

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
