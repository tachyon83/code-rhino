import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
 
public class Main {
 
	static Integer[] r_dp;
	static Integer[] l_dp;
	static int[] seq;
 
	public static void main(String[] args) throws IOException {
 
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
 
		int N = Integer.parseInt(br.readLine());
 
		r_dp = new Integer[N];	// LIS dp
		l_dp = new Integer[N];	// LDS dp
		seq = new int[N];
 
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
 
		for (int i = 0; i < N; i++) {
			seq[i] = Integer.parseInt(st.nextToken());
		}
 
		for (int i = 0; i < N; i++) {
			LIS(i);
			LDS(i);
		}
 
		int max = -1;
		for (int i = 0; i < N; i++) {
			max = Math.max(r_dp[i] + l_dp[i], max);
		}
		System.out.println(max - 1);
 
	}
 
	static int LIS(int N) {
 
		// 만약 탐색하지 않던 위치의 경우
		if (r_dp[N] == null) {
			r_dp[N] = 1; // 1로 초기화
 
			// N 이전의 노드들을 탐색
			for (int i = N - 1; i >= 0; i--) {
				// 이전의 노드 중 seq[N]의 값보다 작은 걸 발견했을 경우
				if (seq[i] < seq[N]) {
					r_dp[N] = Math.max(r_dp[N], LIS(i) + 1);
				}
			}
		}
		return r_dp[N];
	}
 
	static int LDS(int N) {
		
		// 만약 탐색하지 않던 위치의 경우
		if (l_dp[N] == null) {
			l_dp[N] = 1; // 1로 초기화
 
			// N 이후의 노드들을 탐색
			for (int i = N + 1; i < l_dp.length; i++) {
				// 이후의 노드 중 seq[N]의 값보다 작은 걸 발견했을 경우
				if (seq[i] < seq[N]) {
					l_dp[N] = Math.max(l_dp[N], LDS(i) + 1);
				}
			}
		}
		return l_dp[N];
	}
}
