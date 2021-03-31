import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
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

	static int V, E;
	static int[] key;
	static List<Edge>[] adjList;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		V = Integer.parseInt(str.nextToken());
		E = Integer.parseInt(str.nextToken());

		adjList = new ArrayList[V + 1];
		for (int i = 1; i <= V; i++) {
			adjList[i] = new ArrayList<>();
		}

		key = new int[V + 1];

		int a, b, c;

		for (int i = 0; i < E; i++) {
			str = new StringTokenizer(br.readLine(), " ");
			a = Integer.parseInt(str.nextToken());
			b = Integer.parseInt(str.nextToken());
			c = Integer.parseInt(str.nextToken());

			adjList[a].add(new Edge(b, c));
			adjList[b].add(new Edge(a, c));
		}

		bw.write(dijkstra(1, V)+"");
        bw.flush();

	}

	static final int INF = Integer.MAX_VALUE;

	private static int dijkstra(int start, int end) {

		Arrays.fill(key, INF);
		key[start] = 0;

		for (int i = 1; i <= V; i++) {
			Collections.sort(adjList[i]);
		}

		PriorityQueue<Edge> pq = new PriorityQueue<>();
		pq.add(new Edge(start, key[start]));

		while (!pq.isEmpty()) {
			Edge cur = pq.poll();

			for (int i = 0; i < adjList[cur.v].size(); i++) {
				Edge next = adjList[cur.v].get(i);
				if (key[next.v] > next.cost + cur.cost) {
					key[next.v] = next.cost + cur.cost;
					pq.remove(next);
					pq.add(new Edge(next.v, key[next.v]));
				}
			}
		}

		return key[end];

	}

}