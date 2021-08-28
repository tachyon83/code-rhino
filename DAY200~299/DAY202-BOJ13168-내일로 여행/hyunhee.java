import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

	static int N, M, K, R;
	static int[] route;
	static HashMap<String, Integer> city;
	static HashMap<String, Integer> trans;

	static final int INF = Integer.MAX_VALUE;

	static double[][] arr;
	static double[][] brr;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " "); // 1.
		N = Integer.parseInt(str.nextToken());
		R = Integer.parseInt(str.nextToken());
		arr = new double[N + 1][N + 1];
		brr = new double[N + 1][N + 1];
		for (int i = 1; i <= N; i++) {
			Arrays.fill(arr[i], INF);
			Arrays.fill(brr[i], INF);
			brr[i][i] = arr[i][i] = 0;
		}
		city = new HashMap<>();
		trans = new HashMap<>();
		trans.put("Mugunghwa", 0);
		trans.put("ITX-Cheongchun", 0);
		trans.put("ITX-Saemaeul", 0);
		trans.put("V-Train", 1);
		trans.put("S-Train", 1);

		str = new StringTokenizer(br.readLine(), " "); // 2.
		for (int i = 1; i <= N; i++) {
			city.put(str.nextToken(), i);
		}

		M = Integer.parseInt(br.readLine()); // 3.
		route = new int[M];
		str = new StringTokenizer(br.readLine(), " "); // 4
		for (int i = 0; i < M; i++) {
			route[i] = city.get(str.nextToken());
		}

		K = Integer.parseInt(br.readLine()); // 5. 교통수단의 수
		for (int i = 0; i < K; i++) { // Typei, 양 끝 도시 Si, Ei
			str = new StringTokenizer(br.readLine(), " ");
			int type = trans.getOrDefault(str.nextToken(), 2);
			int s = city.get(str.nextToken());
			int e = city.get(str.nextToken());
			int cost = Integer.parseInt(str.nextToken());
			if (type == 0) {
				arr[e][s] = arr[s][e] = 0;
			} else if (type == 1) {
				arr[e][s] = arr[s][e] = Math.min(arr[s][e], cost * 0.5);
			} else {
				arr[e][s] = arr[s][e] = Math.min(arr[s][e], cost);
			}
			brr[e][s] = brr[s][e] = Math.min(brr[s][e], cost);
		}

		floydWarshall();

		double naeil = R, normal = 0;

		for (int i = 0; i < M - 1; i++) {
			naeil += arr[route[i]][route[i + 1]];
			normal += brr[route[i]][route[i + 1]];
		}

		if (naeil < normal) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}

	}

	private static void floydWarshall() {

		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				if (i == k) {
					continue;
				}
				for (int j = 1; j <= N; j++) {
					if (j == k || j == i) {
						continue;
					}
					if (arr[i][k] != INF && arr[k][j] != INF) {
						arr[i][j] = Math.min(arr[i][j], arr[i][k] + arr[k][j]);
					}
					if (brr[i][k] != INF && arr[k][j] != INF) {
						brr[i][j] = Math.min(brr[i][j], brr[i][k] + brr[k][j]);
					}
				}
			}
		}

	}

}