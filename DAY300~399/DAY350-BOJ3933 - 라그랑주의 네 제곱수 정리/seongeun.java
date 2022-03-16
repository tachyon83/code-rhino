import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	static final int MAX = (int)Math.pow(2, 15);
	
	static void makeDP(int[][] dp) {
		
		for(int i = 1; i * i < MAX; i++) {
			
			//dp[i][1]은 항상 1이다.
			dp[i * i][1] = 1;
			
			for(int j = 1; j + (i * i) < MAX; j++) {
				dp[j + (i * i)][2] += dp[j][1];
				dp[j + (i * i)][3] += dp[j][2];
				dp[j + (i * i)][4] += dp[j][3];
			}
		}
	}
	
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int[][] dp = new int[MAX + 1][5];
		
		makeDP(dp);
		
		while(true) {
			int value = Integer.parseInt(input.readLine());
			if( value == 0) break;
			int sum = 0;
			for(int i = 1; i <= 4; i++) sum += dp[value][i];
			sb.append(sum).append("\n");
		}
		System.out.println(sb.toString());
	}

}
