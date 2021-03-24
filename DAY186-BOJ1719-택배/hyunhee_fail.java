package gold4.B1719;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static final int INF = Integer.MAX_VALUE;
	static List<Edge>[] adj;
	
	static int[] key; // 최소비용 저장
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

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		V = Integer.parseInt(str.nextToken());
		E = Integer.parseInt(str.nextToken());

		adj = new ArrayList[V];
		for (int v = 0; v < V; v++) {
			adj[v] = new ArrayList<>();
		}

		key = new int[V];

		for (int e = 0; e < E; e++) {
			str = new StringTokenizer(br.readLine(), " ");
			int start = Integer.parseInt(str.nextToken()) - 1;
			int end = Integer.parseInt(str.nextToken()) - 1;
			int price = Integer.parseInt(str.nextToken());

			adj[start].add(new Edge(end, price));
			adj[end].add(new Edge(start, price));
		}

		for (int i = 0; i < V; i++) {
			dijkstra(i);
			for (int j = 0; j < V; j++) {
				if (key[j] == -1) {
					sb.append("- ");
				} else {
					sb.append(key[j] + " ");
				}
			}
			sb.append("\n");
		}

		bw.write(sb.toString());
		bw.flush();

	}

	private static void dijkstra(int start) {

		PriorityQueue<Edge> pq = new PriorityQueue<>();
		Arrays.fill(key, INF);
		key[start] = 0;
		pq.add(new Edge(start, 0));
		while (!pq.isEmpty()) {

			Edge cur = pq.poll();
			for (int i = 0; i < adj[cur.v].size(); i++) {
				Edge next = adj[cur.v].get(i);
				int temp = key[cur.v] + next.price;
				if (key[next.v] > temp) {
					key[next.v] = temp;
					pq.add(next);
				}
			}

		}
	}

}
