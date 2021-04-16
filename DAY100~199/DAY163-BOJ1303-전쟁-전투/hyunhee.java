import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

	static int R, C;
	static char[][] map;
	static int[][] dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	static int white = 0, blue = 0;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		C = Integer.parseInt(str.nextToken());
		R = Integer.parseInt(str.nextToken());

		map = new char[R][C];
		for (int r = 0; r < R; r++) {
			map[r] = br.readLine().toCharArray();
		}

		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if (map[r][c] == 'W') {
					map[r][c] = ' ';
					count = 0;
					dfs(r, c, 'W');
					white += count * count;
				} else if (map[r][c] == 'B') {
					map[r][c] = ' ';
					count = 0;
					dfs(r, c, 'B');
					blue += count * count;
				}
			}
		}

		bw.write(white + " " + blue);
		bw.flush();

	}

	static int count;

	private static void dfs(int r, int c, char color) {
		count++;
		for (int d = 0; d < dirs.length; d++) {
			int nr = r + dirs[d][0];
			int nc = c + dirs[d][1];

			if (isIn(nr, nc, color)) {
				map[nr][nc] = ' ';
				dfs(nr, nc, color);
			}
		}

	}

	private static boolean isIn(int r, int c, char color) {
		return r >= 0 && r < R && c >= 0 && c < C && map[r][c] == color;
	}

}