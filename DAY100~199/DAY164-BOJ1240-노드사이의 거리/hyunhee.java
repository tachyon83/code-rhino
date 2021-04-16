import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static int[][] map;
	static final int INF = Integer.MAX_VALUE;

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(str.nextToken());
		M = Integer.parseInt(str.nextToken());

		map = new int[N][N];
		for (int i = 0; i < N; i++) {
			Arrays.fill(map[i], INF);
			map[i][i] = 0;
		}

		// 1. 입력
		for (int i = 0; i < N - 1; i++) {
			str = new StringTokenizer(br.readLine(), " ");
			int a = Integer.parseInt(str.nextToken()) - 1;
			int b = Integer.parseInt(str.nextToken()) - 1;
			map[a][b] = Integer.parseInt(str.nextToken());
			map[b][a] = map[a][b];
		}

		floyd();

		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		// 2. M쌍의 노드
		for (int i = 0; i < M; i++) {
			str = new StringTokenizer(br.readLine(), " ");
			bw.write(map[Integer.parseInt(str.nextToken()) - 1][Integer.parseInt(str.nextToken()) - 1] +"");
			bw.newLine();
		}
		
		bw.flush();

	}

	private static void floyd() {

		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (i == j || i == k || j == k) {
						continue;
					}
					if (map[i][k] != INF && map[k][j] != INF) {
						map[i][j] = Math.min(map[i][j], map[i][k] + map[k][j]);
						map[j][i] = map[i][j];
					}
				}
			}
		}


	}

}