package project;

import java.io.*;
import java.util.*;

public class Back_3933 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws Exception {
        int MAX = 1 << 15;  // max=2^15-1 
        int[][] dp = new int[5][MAX]; 

        for (int i = 1; i * i < MAX; i++) {
            int mul = i * i;
            dp[1][mul] = 1;

            for (int j = mul; j < MAX; j++) {
                dp[2][j] += dp[1][j - mul];
                dp[3][j] += dp[2][j - mul];
                dp[4][j] += dp[3][j - mul];
            }
        }

        while (true) {
            int n = Integer.parseInt(br.readLine());
            if(n==0)
                break;

            int result = 0;
            for (int i = 1; i < 5; i++) {
                result += dp[i][n];
            }
            System.out.println(result);
        }

    }


}
