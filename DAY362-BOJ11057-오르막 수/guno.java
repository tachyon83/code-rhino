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

        int n = Integer.parseInt(br.readLine());

        int[][] dp = new int[10][n];

        for (int i = 0; i < 10; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k <= j; k++) {
                    dp[j][i] += dp[k][i - 1];
                }
                dp[j][i] %= 10007;
            }
        }

        int ans = 0;
        for (int i = 0; i < 10; i++) {
            ans += dp[i][n - 1];
        }
        sb.append(ans % 10007);

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
