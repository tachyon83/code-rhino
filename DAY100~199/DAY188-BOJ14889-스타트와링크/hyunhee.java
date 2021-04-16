import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int MIN = Integer.MAX_VALUE;
	static boolean[] team;
	static int[][] Sij;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		Sij = new int[N][N];
		team = new boolean[N];
		for (int n = 0; n < N; n++) {
			StringTokenizer str = new StringTokenizer(br.readLine(), " ");
			for (int m = 0; m < N; m++) {
				Sij[n][m] = Integer.parseInt(str.nextToken());
			}
		} // end input

		combi(0, 0);
		System.out.println(MIN);
	}

	private static void combi(int cur, int cnt) {
		if (cnt == N/2) {
			check();
			return;
		}
		for (int i = cur; i < N; i++) {
			team[i] = true;
			combi(i + 1, cnt + 1);
			team[i] = false;
		}

	}

	private static void check() {
		int a = 0;
		int b = 0;
		for (int i = 0; i < N; i++) {
			if (team[i]) {
				for (int j = 0; j < N; j++) {
					if (team[j]) {
						a += Sij[i][j];
					}
				}
			} else {
				for (int j = 0; j < N; j++) {
					if (!team[j]) {
						b += Sij[i][j];
					}
				}
			}
		}
		MIN = Math.min(Math.abs(a - b), MIN);
	}

}