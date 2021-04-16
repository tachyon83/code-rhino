import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {

	static String[][] map;
	static boolean[][] check;
	static final int N = 5;
	static TreeSet<String> ts = new TreeSet<>();

	public static void main(String[] args) throws IOException {

		map = new String[N][N];
		check = new boolean[N][N];

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for (int i = 0; i < N; i++) {
			StringTokenizer str = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < N; j++) {
				map[i][j] = str.nextToken();
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				check[i][j] = true;
				dfs(i, j, 1, map[i][j]);
				check[i][j] = false;
			}
		}

		System.out.println(ts.size());

	}

	static int[][] dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

	private static void dfs(int r, int c, int depth, String cur) {
		if (depth == 6) {
			ts.add(cur);
			return;
		}

		for (int d = 0; d < dirs.length; d++) {
			int nr = r + dirs[d][0];
			int nc = c + dirs[d][1];
			if (isIn(nr, nc)) {
				dfs(nr, nc, depth + 1, cur + map[nr][nc]);
			}
		}

	}

	private static boolean isIn(int r, int c) {
		return r >= 0 && r < N && c >= 0 && c < N;
	}

}