import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int[] pi, rank;

	static class Edge implements Comparable<Edge> {
		int v1;
		int v2;
		int cost;

		public Edge(int v1, int v2, int cost) {
			this.v1 = v1;
			this.v2 = v2;
			this.cost = cost;
		}

		@Override
		public int compareTo(Edge o) {
			return Integer.compare(this.cost, o.cost);
		}

	}

	static Edge[] edges;
	static int V, E;
	static boolean[] isMan;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		V = Integer.parseInt(str.nextToken());
		E = Integer.parseInt(str.nextToken());

		pi = new int[V + 1];
		rank = new int[V + 1];
		edges = new Edge[E];
		isMan = new boolean[V + 1];

		str = new StringTokenizer(br.readLine(), " ");
		for (int i = 1; i <= V; i++) {
			isMan[i] = "M".equals(str.nextToken());
		}

		int u, v, cost;

		for (int i = 0; i < E; i++) {
			str = new StringTokenizer(br.readLine());
			u = Integer.parseInt(str.nextToken());
			v = Integer.parseInt(str.nextToken());
			cost = Integer.parseInt(str.nextToken());
			edges[i] = new Edge(u, v, cost);
		}

		System.out.println(kruskal());

	}

	private static int kruskal() {

		for (int i = 1; i <= V; i++) {
			makeSet(i);
		}

		Arrays.sort(edges);
		int result = 0, count = 0;
		for (int i = 0; i < E; i++) {
			int px = findSet(edges[i].v1);
			int py = findSet(edges[i].v2);

			if (px == py) {
				continue;
			}
			if (isMan[edges[i].v1] == isMan[edges[i].v2]) {
				continue;
			}

			unionSet(px, py);
			result += edges[i].cost;
			count++;

			if (count == V - 1) {
				return result;
			}
		}
		return -1;
	}

	private static void unionSet(int px, int py) {
		px = findSet(px);
		py = findSet(py);

		if (rank[px] > rank[py]) {
			pi[py] = px;
		} else {
			pi[px] = py;
			if (rank[px] == rank[py]) {
				rank[py]++;
			}
		}
	}

	private static int findSet(int x) {
		if (pi[x] == x) {
			return x;
		}
		return pi[x] = findSet(pi[x]);
	}

	private static void makeSet(int x) {
		pi[x] = x;
	}

}