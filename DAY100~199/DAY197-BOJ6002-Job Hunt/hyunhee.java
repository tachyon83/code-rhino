import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int D, P, C, F, S;

	static class Edge {
		int v1;
		int v2;
		int cost;

		public Edge(int v1, int v2, int cost) {
			this.v1 = v1;
			this.v2 = v2;
			this.cost = cost;
		}

	}

	static int[] key;
	static Edge[] edges;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		D = Integer.parseInt(str.nextToken());
		P = Integer.parseInt(str.nextToken());
		C = Integer.parseInt(str.nextToken());
		F = Integer.parseInt(str.nextToken());
		S = Integer.parseInt(str.nextToken());
		key = new int[C + 1];
		edges = new Edge[P + F];

		int a, b, c;

		for (int i = 0; i < P; i++) {
			str = new StringTokenizer(br.readLine());
			a = Integer.parseInt(str.nextToken());
			b = Integer.parseInt(str.nextToken());
			edges[i] = new Edge(a, b, 0);
		}
		for (int i = P; i < P + F; i++) {
			str = new StringTokenizer(br.readLine());
			a = Integer.parseInt(str.nextToken());
			b = Integer.parseInt(str.nextToken());
			c = Integer.parseInt(str.nextToken());
			edges[i] = new Edge(a, b, c);
		}

		if (bellmanFord()) {
			Arrays.sort(key);
			System.out.println(key[key.length - 1]);
		} else {
			System.out.println(-1);
		}

	}

	static final int MIN = Integer.MIN_VALUE;

	private static boolean bellmanFord() {

		Arrays.fill(key, MIN);
		key[S] = D;

		for (int i = 0; i < C; i++) {
			for (int j = 0; j < P + F; j++) {
				if (key[edges[j].v1] == MIN) {
					continue;
				}
				if (key[edges[j].v2] < key[edges[j].v1] + D - edges[j].cost) {
					key[edges[j].v2] = key[edges[j].v1] + D - edges[j].cost;
					if (i == C - 1) {
						return false;
					}
				}
			}
		}

		return true;

	}

}