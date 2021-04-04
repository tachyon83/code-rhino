import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int V; // T - 시작 정점, V- 정점개수
	static final long INF = Long.MAX_VALUE;

	static class Edge implements Comparable<Edge> {
		int start;
		int end;
		long cost;

		public Edge(int start, int end, long cost) {
			this.start = start;
			this.end = end;
			this.cost = cost;
		}

		@Override
		public int compareTo(Edge o) {
			return Long.compare(this.cost, o.cost);
		}

	}

	static Edge[] edges;
	static int[] pi;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = null;
		V = Integer.parseInt(br.readLine());
		pi = new int[V];
		rank = new int[V];
		int E = (V * (V - 1)) / 2;
		edges = new Edge[E];

		for (int i = 0, k = 0; i < V; i++) {
			str = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < V; j++) {
				int temp = Integer.parseInt(str.nextToken());
				if (i < j) {
					edges[k++] = new Edge(i, j, temp);
				}
			}
		}

		Arrays.sort(edges);

		for (int i = 0; i < V; i++) {
			makeSet(i);
		}

		int cnt = 0;
		long result = 0L;
		for (int i = 0; i < E; i++) {
			int px = findSet(edges[i].start);
			int py = findSet(edges[i].end);

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

		System.out.println(result);

	}

	static int[] rank;

	private static void unionSet(int x, int y) {
		int px = findSet(x);
		int py = findSet(y);

		if (rank[px] < rank[py]) {
			pi[px] = py;
		} else {
			pi[py] = px;
			if (rank[px] == rank[py]) {
				rank[px]++;
			}
		}

	}

	private static int findSet(int x) {
		if (pi[x] == x) {
			return x;
		}
		return findSet(pi[x]);
	}

	private static void makeSet(int i) {
		pi[i] = i;
	}

}