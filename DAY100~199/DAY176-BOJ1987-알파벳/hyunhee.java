import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int R, C;
	static boolean[] alpha = new boolean[26];
	static char[][] map;
	static int answer = -1;

	public static void main(String[] args) throws IOException {

		initGame();
		alpha[map[0][0] - 'A'] = true;
		dfs(0, 0, 1);

		System.out.println(answer);

	}

	static int[][] dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

	private static void dfs(int r, int c, int count) {
		answer = Math.max(answer, count);
		int nr, nc;
		for (int d = 0; d < dirs.length; d++) {
			nr = r + dirs[d][0];
			nc = c + dirs[d][1];

			if (canGo(nr, nc)) {
				alpha[map[nr][nc] - 'A'] = true;
				dfs(nr, nc, count + 1);
				alpha[map[nr][nc] - 'A'] = false;
			}
		}
	}

	private static boolean canGo(int r, int c) {
		return r >= 0 && r < R && c >= 0 && c < C && !alpha[map[r][c] - 'A'];
	}

	private static void initGame() throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		R = Integer.parseInt(str.nextToken());
		C = Integer.parseInt(str.nextToken());

		map = new char[R][C];
		for (int r = 0; r < R; r++) {
			map[r] = br.readLine().toCharArray();
		}

	}

}