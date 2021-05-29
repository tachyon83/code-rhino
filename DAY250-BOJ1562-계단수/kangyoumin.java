import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static int n, mod = 1000000000, visit = 1<<10;
	static long dp[][][] = new long[101][10][visit];
	
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		System.out.println(cal());
	}
	
	public static long cal() {
		long sum=0;
		int i, j, k, bit;

		for(i = 1; i < 10; i++) {
			dp[1][i][1<<i] = 1;
		}
			
		for (i = 2; i <= n; i++) {
			for (j = 0; j <= 9; j++) {
				for(k = 0; k < visit; k++) {
					bit = k | (1<<j);
					dp[i][j][bit] = (dp[i][j][bit] + 
                                     ((0<j ? dp[i-1][j-1][k] : 0) +
                                      (j<9 ? dp[i-1][j+1][k] : 0))%mod
                                     )%mod;
				}
			}
		}
		
		for (i = 0; i < 10; i++) { 
			sum = (sum + dp[n][i][visit-1])%mod;
		}
		return sum;
	}

}
