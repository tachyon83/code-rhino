import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 동적 프로그래밍 
// 제곱수의 합
public class Main {
	static int[] dp;
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.valueOf(br.readLine());
		dp = new int[100001];
	
		// 대신, 1이 몇 개 존재하는지 초기 설정을 해준다. (최댓값으로 초기 설정)
		for(int i = 1; i <= n; i++) {
			dp[i] = i;
		}
		
		for(int i = 1; i <= n; i++) {
			
			// 최소가 되는 제곱수 = n의 이전 수 들 중 제곱수 + n - 제곱수의 최수항 개수 
			for(int j = 1; j * j <= i; j++) {
				if(dp[i] > dp[i - (j * j)] + 1) { // 
					dp[i] = dp[i - (j * j)] + 1;
				}
			}
		}
		
		System.out.println(dp[n]);
	}
}
