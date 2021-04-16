import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// Combination

public class Main {

	static boolean[] check = new boolean[9];
	static int[] height = new int[9];

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int i = 0; i < 9; i++) {
			height[i] = Integer.parseInt(br.readLine());
		}

		Arrays.sort(height);

		dfs(0, 0, 0);

	}

	private static void dfs(int cur, int cnt, int sum) {
		if (sum > 100) {
			return;
		}
		if (cnt == 7) {
			if (sum == 100) {
				StringBuilder sb = new StringBuilder();
				for (int i = 0; i < 9; i++) {
					if (check[i]) {
						sb.append(height[i]).append("\n");
					}
				}
				System.out.println(sb.toString());
				System.exit(0);
			}
			return;
		}

		for (int i = cur; i < 9; i++) {
			if (!check[i]) {
				check[i] = true;
				dfs(i + 1, cnt + 1, sum + height[i]);
				check[i] = false;
			}
		}
	}

}