import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static List<Edge>[] adj;
	static int V, E;
	static int[] key; // 최소 비용 저장할 배열

	static class Edge implements Comparable<Edge> {
		int end;
		int price;

		public Edge(int end, int price) {
			this.end = end;
			this.price = price;
		}

		@Override
		public int compareTo(Edge o) {
			return this.price - o.price;
		}

	}

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		V = Integer.parseInt(str.nextToken());
		E = Integer.parseInt(str.nextToken());

		key = new int[V];
		adj = new ArrayList[V];
		for (int v = 0; v < V; v++) {
			adj[v] = new ArrayList<>();
		}

		for (int e = 0; e < E; e++) {
			str = new StringTokenizer(br.readLine(), " ");
			int start = Integer.parseInt(str.nextToken()) - 1;
			int end = Integer.parseInt(str.nextToken()) - 1;
			int price = Integer.parseInt(str.nextToken());
			adj[start].add(new Edge(end, price));
			adj[end].add(new Edge(start, price));
		}

		str = new StringTokenizer(br.readLine(), " ");
		int v1 = Integer.parseInt(str.nextToken()) - 1;
		int v2 = Integer.parseInt(str.nextToken()) - 1;

		int d1 = dijkstra(0, v1); // 1.
		int d2 = dijkstra(v1, v2); // 1. 2.
		int d3 = dijkstra(v2, V - 1); // 1.
		int d4 = dijkstra(0, v2); // 2.
		int d5 = dijkstra(v1, V - 1); // 2.

		int result = INF;
		if (d1 != INF && d2 != INF && d3 != INF) {
			result = Math.min(result, d1 + d2 + d3);
		}
		if (d2 != INF && d4 != INF && d5 != INF) {
			result = Math.min(result, d2 + d4 + d5);
		}

		System.out.println(result == INF ? -1 : result);

	}

	static final int INF = Integer.MAX_VALUE;

	private static int dijkstra(int start, int end) {

		PriorityQueue<Edge> pq = new PriorityQueue<>();
		Arrays.fill(key, INF);

		key[start] = 0;
		pq.add(new Edge(start, 0));
		while (!pq.isEmpty()) {
			Edge cur = pq.poll();
			for (int i = 0; i < adj[cur.end].size(); i++) {
				Edge next = adj[cur.end].get(i);
				if (key[next.end] > key[cur.end] + next.price) {
					key[next.end] = key[cur.end] + next.price;
					pq.add(next);
				}
			}

		}

		return key[end];

	}

}