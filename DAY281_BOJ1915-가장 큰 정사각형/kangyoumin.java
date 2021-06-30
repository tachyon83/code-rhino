
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());


		if (N == 1 && M == 1) {
			bw.write("1\n");
			bw.flush();
			bw.close();
			br.close();
			return;
		}

		int ans = 0;

		int[][] dp = new int[N + 1][M + 1];
		for (int i = 1; i <= N; i++) {
			String[] input = br.readLine().split("");

			for (int j = 1; j <= M; j++) {
				int temp = Integer.parseInt(input[j - 1]);

				if (i == 1 && j == 1) { 
					dp[i][j] = temp;
				} else { 
					if (temp == 1) {
						dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])) + 1;
						ans = Math.max(ans, dp[i][j]);
					}
				}
			}
		}

		bw.write(ans * ans + "\n");
		bw.flush();
		bw.close();
		br.close();
	}

}
