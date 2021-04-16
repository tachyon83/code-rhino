import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int V, E;
	static int start, end;

	static class Point {
		int s;
		int e;
		int cost;

		public Point(int s, int e, int cost) {
			this.s = s;
			this.e = e;
			this.cost = cost;
		}

	}

	static long[] key;
	static int[] money; // 각 노드에서 벌 수 있는 돈
	static Point[] edges;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		V = Integer.parseInt(str.nextToken()); // 도시의 개수
		start = Integer.parseInt(str.nextToken()); // 시작 도시
		end = Integer.parseInt(str.nextToken()); // 도착 도시
		E = Integer.parseInt(str.nextToken()); // 교통 수단 개수

		key = new long[V]; // 최대비용을 저장할 공간
		money = new int[V]; // 각 도시에서 얻을 수 있는 금액
		edges = new Point[E]; // 교통수단의 정보
		int a, b, c;
		for (int i = 0; i < E; i++) {
			str = new StringTokenizer(br.readLine(), " ");
			a = Integer.parseInt(str.nextToken());
			b = Integer.parseInt(str.nextToken());
			c = Integer.parseInt(str.nextToken());
			edges[i] = new Point(a, b, -c); // 간선은 현재 가진 돈에서 소비하는 돈
		}
		str = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < V; i++) {
			money[i] = Integer.parseInt(str.nextToken());
		}

		System.out.println(bellmanFord());

	}

	static final long MIN = Long.MIN_VALUE;
	static final long MAX = Long.MAX_VALUE;

	private static String bellmanFord() {

		Arrays.fill(key, MIN);
		key[start] = money[start];

		for (int i = 0; i < V + E; i++) {
			boolean flag = false;
			for (int j = 0; j < E; j++) {

				if (key[edges[j].s] == MIN) {
					continue;
				}
				if (key[edges[j].s] == MAX) {
					flag = true;
					key[edges[j].e] = MAX;
					continue;
				}

				if (key[edges[j].e] < key[edges[j].s] + edges[j].cost + money[edges[j].e]) {
					key[edges[j].e] = key[edges[j].s] + edges[j].cost + money[edges[j].e];

					if (i >= V - 1 || key[edges[j].e] >= MAX) {
						key[edges[j].e] = MAX;
					}
					flag = true;
				}

			}
			if (!flag) {
				break;
			}
		}

		return key[end] == MAX ? "Gee" : key[end] == MIN ? "gg" : (key[end] + "");
	}

}