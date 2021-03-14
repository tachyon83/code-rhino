import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int R, C;
	static int[] answer = new int[2]; // sheep, wolf
	static char[][] map;

	static class Field {
		int r, c;

		public Field(int r, int c) {
			this.r = r;
			this.c = c;
		}

	}

	public static void main(String[] args) throws IOException {

		initGame();

		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if (map[r][c] == 'o') {
					bfs(r, c, 1, 0);
				} else if (map[r][c] == 'v') {
					bfs(r, c, 0, 1);
				}
			}
		}

		System.out.println(answer[0] + " " + answer[1]);

	}

	static int[][] dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

	private static void bfs(int r, int c, int sheep, int wolf) {
		map[r][c] = ',';

		Queue<Field> queue = new LinkedList<>();
		queue.offer(new Field(r, c));

		while (!queue.isEmpty()) {

			Field f = queue.poll();
			int nr, nc;
			for (int d = 0; d < dirs.length; d++) {
				nr = f.r + dirs[d][0];
				nc = f.c + dirs[d][1];
				if (canGo(nr, nc)) {
					if (map[nr][nc] == 'o') {
						sheep++;
					} else if (map[nr][nc] == 'v') {
						wolf++;
					}
					map[nr][nc] = ',';
					queue.offer(new Field(nr, nc));
				}
			}

		}

		if (sheep > wolf) {
			answer[0] += sheep;
		} else {
			answer[1] += wolf;
		}

	}

	private static boolean canGo(int r, int c) {
		String go = ".ov";
		return r >= 0 && r < R && c >= 0 && c < C && go.contains(map[r][c] + "");
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