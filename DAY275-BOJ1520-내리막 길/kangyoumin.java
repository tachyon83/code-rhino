import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int M, N;
	static int[][] arr;
	static int[][] dp;
	static int[] x = {0, 1, 0, -1};
	static int[] y = {1, 0, -1, 0};

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		dp = new int[M+1][N+1];
		arr = new int[M+1][N+1];
		for(int i = 1; i < M+1; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 1; j < N+1; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
//				0이게 되면 경로숫자가 0일경우도 있다.
				dp[i][j] = -1;
			}
		}
//		도착지점부터 거꾸로 온다
		System.out.println(dfs(1, 1));
		
	}
	
	static int dfs(int m, int n) {
		dp[m][n] = 0;
		
		for(int i = 0; i < 4; i++) {
			int _m = m+x[i];
			int _n = n+y[i];
			
			if((0 < _m && _m <= M) && (0 < _n && _n <= N)) {
				if(arr[_m][_n] < arr[m][n]) {
//					도착지점까지 왔다면 도착지점전에 ++, 왜냐면 도착지점은 0
					if(_m == M && _n == N)
						dp[m][n] += 1;
					if(dp[_m][_n] >= 0) 
//						한번이라도 가서 경로의 개수가 있다면
						dp[m][n] += dp[_m][_n];
					else
//						-1이라서 한번도 안갔고, 그렇다면 경로 개수 개산해서 더해주기
						dp[m][n] += dfs(_m, _n);
				}
			}
		}
		
		return dp[m][n];
	}

}
