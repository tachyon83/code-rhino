import java.io.*;
import java.util.*;

public class Main {
    static long MOD=1000000000;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;

        st=new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken()),k=Integer.parseInt(st.nextToken());
        long[][] dp=new long[k+1][n+1];
        for (int i = 0; i < k+1; i++) {
            dp[i][0]=1;
        }
        for (int i = 1; i < k+1; i++) {
            for (int j = 1; j < n+1; j++) {
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
            }
        }
        sb.append(dp[k][n]);

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
