import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Main {

	static int N;
	static Map<Integer, Integer> home = new HashMap<>();
	static int[][] map;
	static int danji;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		for (int r = 0; r < N; r++) {
			char[] input = br.readLine().toCharArray();
			for (int c = 0; c < N; c++) {
				map[r][c] = input[c] - '1';
			}
		}
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (map[r][c] == 0) {
					danji++;
					map[r][c] = danji;
					home.put(danji, 0);
					dfs(r, c);
				}
			}
		}

		System.out.println(danji);
		int[] count = new int[danji];
		for (int i = 1; i <= danji; i++) {
			count[i-1] = home.get(i);
		}
		Arrays.sort(count);
		for (int i = 0; i < danji; i++) {
			System.out.println(count[i]);
		}

	}

	static int[][] dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

	private static void dfs(int r, int c) {
		int cnt = home.remove(danji);
		home.put(danji, cnt + 1);

		int nr, nc;

		for (int d = 0; d < dirs.length; d++) {
			nr = r + dirs[d][0];
			nc = c + dirs[d][1];
			if (isIn(nr, nc) && map[nr][nc] == 0) {
				map[nr][nc] = danji;
				dfs(nr, nc);
			}
		}

	}

	private static boolean isIn(int r, int c) {
		return r >= 0 && r < N && c >= 0 && c < N;
	}

}
