import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static int[][] key; // [2][V]
	static int V, E;

	static class Edge implements Comparable<Edge> {
		int v;
		int price;

		public Edge(int v, int price) {
			this.v = v;
			this.price = price;
		}

		@Override
		public int compareTo(Edge o) {
			return Integer.compare(this.price, o.price);
		}

	}

	static List<Edge>[] adj;
	static final int INF = Integer.MAX_VALUE;
	static int MIN = INF;
	static int[] building = new int[2];

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		V = Integer.parseInt(str.nextToken());
		adj = new ArrayList[V];
		for (int i = 0; i < V; i++) {
			adj[i] = new ArrayList<>();
		}
		key = new int[2][V];
		E = Integer.parseInt(str.nextToken());
		for (int i = 0; i < E; i++) {
			str = new StringTokenizer(br.readLine(), " ");
			int v1 = Integer.parseInt(str.nextToken()) - 1;
			int v2 = Integer.parseInt(str.nextToken()) - 1;
			adj[v1].add(new Edge(v2, 1));
			adj[v2].add(new Edge(v1, 1));
		}

		for (int i = 0; i < V; i++) {
			for (int j = i + 1; j < V; j++) {
				int[] start = { i, j };
				dijkstra(start);
			}
		}
		Arrays.sort(building);
		System.out.println((building[0] + 1) + " " + (building[1] + 1) + " " + MIN * 2);

	}

	private static void dijkstra(int[] start) {

		for (int i = 0; i < 2; i++) {
			PriorityQueue<Edge> pq = new PriorityQueue<>();
			Arrays.fill(key[i], INF);

			pq.offer(new Edge(start[i], 0));
			key[i][start[0]] = 0;
			key[i][start[1]] = 0;

			while (!pq.isEmpty()) {
				Edge cur = pq.poll();
				for (int j = 0; j < adj[cur.v].size(); j++) {
					Edge next = adj[cur.v].get(j);
					if (key[i][next.v] > key[i][cur.v] + next.price) {
						key[i][next.v] = key[i][cur.v] + next.price;
						pq.offer(next);
					}
				}
			}
		}
		int answer = 0;
		for (int i = 0; i < V; i++) {
			answer += Math.min(key[0][i], key[1][i]);
		}
		if (MIN > answer) {
			building[0] = start[0];
			building[1] = start[1];
			MIN = answer;
		}

	}

}
