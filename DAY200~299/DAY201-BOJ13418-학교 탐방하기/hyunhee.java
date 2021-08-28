import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

	static class Edge {
		int v1;
		int v2;
		int cost;

		public Edge(int v1, int v2, int cost) {
			this.v1 = v1;
			this.v2 = v2;
			this.cost = cost;
		}

		@Override
		public String toString() {
			return "Edge [v1=" + v1 + ", v2=" + v2 + ", cost=" + cost + "]";
		}

	}

	static Edge[] edges;
	static int V, E;
	static int[] pi, rank;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		V = Integer.parseInt(str.nextToken());
		E = Integer.parseInt(str.nextToken());
		pi = new int[V + 1];
		rank = new int[V + 1];
		edges = new Edge[E];
		int a, b, c;
		str = new StringTokenizer(br.readLine(), " ");
		str.nextToken();
		str.nextToken();
		int result = (Integer.parseInt(str.nextToken()) + 1) % 2;
		for (int i = 0; i < E; i++) {
			str = new StringTokenizer(br.readLine(), " ");
			a = Integer.parseInt(str.nextToken());
			b = Integer.parseInt(str.nextToken());
			c = (Integer.parseInt(str.nextToken()) + 1) % 2;
			edges[i] = new Edge(a, b, c);
		}

		Arrays.sort(edges, new Comparator<Edge>() {

			@Override
			public int compare(Edge o1, Edge o2) {
				return Integer.compare(o1.cost, o2.cost);
			}
		});
		int min = kruskal(result);

		Arrays.sort(edges, new Comparator<Edge>() {

			@Override
			public int compare(Edge o1, Edge o2) {
				return Integer.compare(o2.cost, o1.cost);
			}

		});

		int max = kruskal(result);
		System.out.println(max - min);

	}

	static final int INF = Integer.MAX_VALUE;

	private static int kruskal(int result) {
		int cnt = 0;
		for (int i = 1; i <= V; i++) {
			makeSet(i);
		}

		for (int i = 0; i < E; i++) {
			int px = findSet(edges[i].v1);
			int py = findSet(edges[i].v2);

			if (px == py) {
				continue;
			}
			unionSet(px, py);
			result += edges[i].cost;
			cnt++;
			if (cnt == V - 1) {
				break;
			}
		}
		return result * result;
	}

	private static void unionSet(int x, int y) {
		int px = findSet(x);
		int py = findSet(y);
		if (rank[px] > rank[py]) {
			pi[py] = pi[px];
		} else {
			pi[px] = pi[py];
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