import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;

        int t=Integer.parseInt(br.readLine());
        while (t-->0){
            int k=Integer.parseInt(br.readLine());
            st=new StringTokenizer(br.readLine());
            int[][] dp=new int[k][k];
            int[] ps=new int[k+1];
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    dp[i][j]=Integer.MAX_VALUE;
                }
            }
            for (int i = 0; i < k; i++) {
                int temp=Integer.parseInt(st.nextToken());
                dp[i][i]=0;
                ps[i+1]=ps[i]+temp;
            }
            for (int len = 2; len <= k; len++) {
                for (int l = 0; l+len-1< k; l++) {
                    int r=l+len-1;
                    int temp=ps[r+1]-ps[l];
                    for (int m = l; m < r; m++) {
                        dp[l][r]=Math.min(dp[l][r], dp[l][m]+dp[m+1][r] + temp);
                    }
                }
            }
            sb.append(dp[0][k-1]).append("\n");

        }

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
