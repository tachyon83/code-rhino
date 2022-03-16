import java.io.*;
import java.util.*;

public class Main {
    static int[] nums;
    static int[][] dp;
    static int INF = Integer.MAX_VALUE;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
        while (T-->0){
            int n = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            nums = new int[n];
            for (int i = 0; i < n; i++) {
                nums[i] = Integer.parseInt(st.nextToken());
            }
            dp = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i][j] = INF;
                }
            }

            sb.append(getScore(0,n-1,true)).append("\n");
        }

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

    static int getScore(int l,int r,boolean flag){
        if(l==r){
            if(flag)
                return nums[l];
            else
                return 0;
        }
        if(dp[l][r]!=INF)
            return dp[l][r];

        int scoreL = getScore(l,r-1,!flag);
        int scoreR = getScore(l+1,r,!flag);
        int ret;
        if(flag)
            ret = Math.max(scoreL+nums[r],scoreR+nums[l]);
        else
            ret = Math.min(scoreL,scoreR);

        return dp[l][r]=ret;

    }

}
