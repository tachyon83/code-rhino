import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N, M, X;
	static int[][] map;
	static final int INF = Integer.MAX_VALUE;

	public static void main(String[] args) throws IOException {

		initGame();

		floydwashall();
		int max = -1;
		for (int i = 1; i <= N; i++) {
			max = Math.max(max, map[i][X] + map[X][i]);
		}

		System.out.println(max);

	}

	private static void floydwashall() {

		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				if (i == k) {
					continue;
				}
				for (int j = 1; j <= N; j++) {
					if (i == j || j == k || map[i][k] == INF || map[k][j] == INF) {
						continue;
					}
					map[i][j] = Math.min(map[i][j], map[i][k] + map[k][j]);
				}
			}
		}

	}

	private static void initGame() throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(str.nextToken());
		M = Integer.parseInt(str.nextToken());
		X = Integer.parseInt(str.nextToken());

		map = new int[N + 1][N + 1];
		for (int i = 1; i <= N; i++) {
			Arrays.fill(map[i], INF);
			map[i][i] = 0;
		}
		int s, e, t;
		for (int m = 0; m < M; m++) {
			str = new StringTokenizer(br.readLine(), " ");
			s = Integer.parseInt(str.nextToken());
			e = Integer.parseInt(str.nextToken());
			t = Integer.parseInt(str.nextToken());
			map[s][e] = t;
		}

	}

}