import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int[][] map;
	static int idx;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			N = Integer.parseInt(br.readLine());
			map = new int[2][N];
			for (int i = 0; i < 2; i++) {
				StringTokenizer str = new StringTokenizer(br.readLine(), " ");
				for (int n = 0; n < N; n++) {
					map[i][n] = Integer.parseInt(str.nextToken());
				}
			}
			int answer = 0;
			int count = 0;
			while (count < 2 * N) {
				int maxR = -1, maxC = -1, maxVal = -1;
				for (int i = 0; i < 2; i++) {
					for (int n = 0; n < N; n++) {
						if (map[i][n] > -1 && map[i][n] > maxVal) {
							maxR = i;
							maxC = n;
							maxVal = map[i][n];
						}
					}
				}
				answer += maxVal;
				count++;
				map[maxR][maxC] = -1;
				for (int d = 0; d < 4; d++) {
					int nr = maxR + dirs[d][0];
					int nc = maxC + dirs[d][1];
					if (isIn(nr, nc)) {
						map[nr][nc] = -1;
						count++;
					}
				}
			}
			
			System.out.println(answer);
		}

	}

	static int[][] dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

	private static boolean isIn(int r, int c) {
		return !(r < 0 || r >= 2 || c < 0 || c >= N) && map[r][c] > -1;
	}

}