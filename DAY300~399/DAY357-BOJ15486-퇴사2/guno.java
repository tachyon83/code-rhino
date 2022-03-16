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
        int[] t = new int[n + 1];
        int[] p = new int[n + 1];
        int[] dp = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            getSt();
            t[i] = getInt();
            p[i] = getInt();
        }
        for (int now = 1; now <= n; now++) {
            int endDay = now + t[now] - 1;
            dp[now] = Math.max(dp[now], dp[now - 1]);
            if (endDay > n) {
                continue;
            }
            dp[endDay] = Math.max(dp[endDay], dp[now - 1] + p[now]);
        }

        sb.append(dp[n]);

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

}
