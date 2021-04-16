package gold4.B4485;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static int V;
	static int[][] key;
	static int[][] adj;
	static int[][] dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

	static class Edge implements Comparable<Edge> {
		int r;
		int c;
		int cost;

		public Edge(int r, int c, int cost) {
			this.r = r;
			this.c = c;
			this.cost = cost;
		}

		@Override
		public int compareTo(Edge o) {
			return Integer.compare(this.cost, o.cost);
		}

	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = null;
		StringBuilder sb = new StringBuilder();
		V = Integer.parseInt(br.readLine());
		int idx = 1;
		do {
			adj = new int[V][V];
			key = new int[V][V];
			for (int i = 0; i < V; i++) {
				str = new StringTokenizer(br.readLine(), " ");
				for (int j = 0; j < V; j++) {
					adj[i][j] = Integer.parseInt(str.nextToken());
				}
			}

			sb.append("Problem ").append(idx++).append(": ").append(dijkstra(0, 0)).append("\n");
			V = Integer.parseInt(br.readLine());
		} while (V != 0);
		
		System.out.println(sb.toString());

	}

	static final int INF = Integer.MAX_VALUE;

	private static int dijkstra(int r, int c) {

		int nr, nc;

		for (int i = 0; i < V; i++) {
			Arrays.fill(key[i], INF);
		}
		key[r][c] = adj[r][c];
		PriorityQueue<Edge> pq = new PriorityQueue<>();
		pq.add(new Edge(r, c, key[r][c]));

		while (!pq.isEmpty()) {
			Edge cur = pq.poll();

			for (int d = 0; d < dirs.length; d++) {
				nr = cur.r + dirs[d][0];
				nc = cur.c + dirs[d][1];
				if (isIn(nr, nc) && key[nr][nc] > cur.cost + adj[nr][nc]) {
					key[nr][nc] = cur.cost + adj[nr][nc];
					pq.add(new Edge(nr, nc, key[nr][nc]));
				}
			}
		}

		return key[V - 1][V - 1];
	}

	private static boolean isIn(int r, int c) {
		return r >= 0 && r < V && c >= 0 && c < V;
	}

}
