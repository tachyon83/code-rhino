import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static int[] map;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");

		N = Integer.parseInt(str.nextToken());
		M = Integer.parseInt(str.nextToken());
		map = new int[N + 2];

		for (int n = 1; n <= N; n++) {
			map[n] = Integer.parseInt(br.readLine());
		}

		int[] dice = new int[M];
		for (int m = 0; m < M; m++) {
			dice[m] = Integer.parseInt(br.readLine());
		}

		// end input
		int index = 1;
		for (int m = 1; m <= M; m++) {
			index += dice[m - 1];
			if (index >= 1 && index < N) {
				if (map[index] != 0) {
					index += map[index];
				}
			}

			if (index >= N) {
				System.out.println(m);
				System.exit(0);
			}
		}
	}

}