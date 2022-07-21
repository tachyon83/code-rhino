import java.io.*;
import java.util.*;



public class jiwoong{
    public static void main(String []args) throws Exception{
        BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));

        char[] str1 = br.readLine().toCharArray();
        char[] str2 = br.readLine().toCharArray();

        int l1 = str1.length;
        int l2 = str2.length;

        int[][] dp = new int[l1+1][l2+1];

        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){

                if(str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        System.out.println(dp[l1][l2]);
    }
}