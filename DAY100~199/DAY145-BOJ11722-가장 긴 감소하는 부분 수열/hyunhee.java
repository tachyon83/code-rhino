import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		int[] A = new int[N];
		int[] dp = new int[N];
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		for (int n = 0; n < N; n++) {
			A[n] = Integer.parseInt(str.nextToken());
		}
		for (int n = 0; n < N; n++) {
			dp[n] = 1;
			for (int i = 0; i < n; i++) {
				if (A[i] > A[n] && dp[n] < (dp[i] + 1)) {
					dp[n] = dp[i] + 1;
				}
			}
		}
		Arrays.sort(dp);
		System.out.println(dp[N - 1]);

	}

}