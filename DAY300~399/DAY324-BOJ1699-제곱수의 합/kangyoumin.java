import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static int[] dp;
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.valueOf(br.readLine());
		dp = new int[100001];
		for(int i = 1; i <= n; i++) {
			dp[i] = i;
		}
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j * j <= i; j++) {
				if(dp[i] > dp[i - (j * j)] + 1) { // 
					dp[i] = dp[i - (j * j)] + 1;
				}
			}
		}
		
		System.out.println(dp[n]);
	}
}
