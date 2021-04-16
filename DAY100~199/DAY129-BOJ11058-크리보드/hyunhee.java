/**
 * 
 * DP - 점화식 문제
 * f(0) = 0
 * f(n) = f(n-1) + 1;	// 첫 번째 버튼 클릭 시
 * f(n) = f(k) * (n-k-1)	// k < n-4 일 때
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		long[] dp = new long[N+1];
		for(int n=1;n<=N;n++) {
			dp[n] = dp[n-1]+1;
			for(int k=n-3;k>=0;k--) {
				dp[n] = Math.max(dp[n], dp[k] * (n-k-1));
			}
		}
		
		System.out.println(dp[N]);
		
	}

}