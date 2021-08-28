import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static long DIV = 1000000009;
	static long dp[];
	static int T, n;

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
		dp = new long[1000001];
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		
//		dp에 모든 숫자에 해당하는 값넣기
		for(int j = 4; j <= 1000000; j++) {
				dp[j] = (dp[j-1]+dp[j-2]+dp[j-3])%DIV;
		}
//	테스트 케이스에 맞는 값을 dp에서 찾아서 출력
		for(int i = 0; i < T; i++) {
			n = Integer.parseInt(br.readLine());
			System.out.println(dp[n]);
		}
	}
}
