//성공
import java.util.*;



public class Main{
	
	static int max(int a, int b) {
		if(a>b)
			return a;
		return b;
	}
	
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		//테스트 개수만큼 실행
		for(int i=0;i<t;i++) {
			int n = sc.nextInt();
			
			//스티커 점수 생성
			int array[][] = new int [2][n+1];
			int[][] dp = new int [2][n+1];
		
			//입력 받기 완료
			for(int j=0;j<2;j++) {
				for(int k=1;k<=n;k++) {
					array[j][k] = sc.nextInt();
				}

			}
			
			
			array[0][0] = array[1][0] = 0;
			dp[0][0] = dp[1][0] = 0;
			dp[0][1] = array[0][1];
			dp[1][1] = array[1][1];
			for(int u = 2; u<=n; u++) {
				dp[0][u] = max(dp[1][u-2],dp[1][u-1]) + array[0][u];
				dp[1][u] = max(dp[0][u-2],dp[0][u-1]) + array[1][u];
			}
			
			System.out.println(max(dp[0][n],dp[1][n]));
		}
		
	}
}
