import java.io.*;
import java.util.*;

public class Main {
	public static int N;
	public static int[] cards;
	public static int[][][] dp;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		for (int tc = 0; tc < T; tc++) {
			N = Integer.parseInt(br.readLine());
			cards = new int[N];
			st = new StringTokenizer(br.readLine());;
			for (int i = 0; i < N; i++) {
				cards[i] = Integer.parseInt(st.nextToken());
			}
			
			dp = new int[2][N][N];
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < N; j++) {
					Arrays.fill(dp[i][j], -1);
				}
			}
			System.out.println(solve(0, 0, N-1));
		}
	}
	
	public static int solve(int turn, int start, int end) {
		if (dp[turn][start][end] != -1) {
			return dp[turn][start][end];
		}
		
		if (start == end) {
			if (turn == 0) return cards[start];
			else return 0;
		}
		
		dp[turn][start][end] = 0;
		if (turn == 0) {
			dp[turn][start][end] = Math.max(solve(1, start + 1, end) + cards[start], solve(1, start, end - 1) + cards[end]);
		} else { 
			dp[turn][start][end] = Math.min(solve(0, start + 1, end), solve(0, start, end - 1));
		}
		return dp[turn][start][end];
	}
}
