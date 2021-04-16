import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int[][] dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	static int[][] map;
	static int[][] memoi;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		memoi = new int[N][N];
		for (int r = 0; r < N; r++) {
			StringTokenizer str = new StringTokenizer(br.readLine(), " ");
			for (int c = 0; c < N; c++) {
				map[r][c] = Integer.parseInt(str.nextToken());
			}
		}
		int answer = 0;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				// 출발
				answer = Math.max(answer, dfs(r, c));
			}
		}
		
		System.out.println(answer);

	}

	private static int dfs(int r, int c) {
		if (memoi[r][c] == 0) {
			memoi[r][c] = 1;
			for (int d = 0; d < dirs.length; d++) {
				int nr = r + dirs[d][0];
				int nc = c + dirs[d][1];
				if (isIn(nr, nc) && isGo(map[nr][nc], map[r][c])) {
					memoi[r][c] = Math.max(memoi[r][c], dfs(nr, nc) + 1);
				}
			}
		}
		return memoi[r][c];
	}

	private static boolean isGo(int next, int cur) {
		return next > cur;
	}

	private static boolean isIn(int r, int c) {
		return r >= 0 && r < N && c >= 0 && c < N;
	}

}