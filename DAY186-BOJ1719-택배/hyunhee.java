import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static class Edge implements Comparable<Edge> {
		int v;
		int cost;

		public Edge(int v, int cost) {
			this.v = v;
			this.cost = cost;
		}

		@Override
		public int compareTo(Edge o) {
			return Integer.compare(this.cost, o.cost);
		}

	}

	static int[][] key;
	static int[][] pi;
	static List<Edge>[] adjList;
	static int V, E;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		V = Integer.parseInt(str.nextToken());
		E = Integer.parseInt(str.nextToken());
		adjList = new ArrayList[V + 1];
		for (int i = 1; i <= V; i++) {
			adjList[i] = new ArrayList<>();
		}
		key = new int[V + 1][V + 1];
		pi = new int[V + 1][V + 1];
		for (int i = 0; i < E; i++) {
			str = new StringTokenizer(br.readLine(), " ");
			int a = Integer.parseInt(str.nextToken());
			int b = Integer.parseInt(str.nextToken());
			int c = Integer.parseInt(str.nextToken());
			adjList[a].add(new Edge(b, c));
			adjList[b].add(new Edge(a, c));
		}

		for (int i = 1; i <= V; i++) {
			dijkstra(i, key[i], pi[i]);
		}

		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (i == j) {
					sb.append("- ");
				} else {
					sb.append(pi[i][j] + " ");
				}
			}
			sb.append("\n");
		}

		System.out.println(sb.toString());

	}

	static final int INF = Integer.MAX_VALUE;

	private static void dijkstra(int start, int[] dist, int[] parent) {

		Arrays.fill(key[start], INF);
		dist[start] = 0;
		parent[start] = start;

		PriorityQueue<Edge> pq = new PriorityQueue<>();
		pq.add(new Edge(start, dist[start]));

		while (!pq.isEmpty()) {
			Edge cur = pq.poll();
			if (dist[cur.v] < cur.cost) {
				continue;
			}
			for (int i = 0; i < adjList[cur.v].size(); i++) {
				Edge next = adjList[cur.v].get(i);

				if (dist[next.v] > next.cost + cur.cost) {
					dist[next.v] = next.cost + cur.cost;
					if (cur.v == start) {
						parent[next.v] = next.v;
					} else {
						parent[next.v] = parent[cur.v];
					}
					pq.add(new Edge(next.v, dist[next.v]));
				}
			}
		}

	}

}