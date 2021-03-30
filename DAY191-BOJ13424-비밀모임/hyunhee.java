import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static final int INF = Integer.MAX_VALUE;
	static int[][] key;
	static List<Edge>[] adjList;

	static class Edge {
		int v;
		int cost;

		public Edge(int v, int cost) {
			this.v = v;
			this.cost = cost;
		}

	}

	static int T, V, E, K;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = null;
		T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			str = new StringTokenizer(br.readLine(), " ");
			V = Integer.parseInt(str.nextToken());
			E = Integer.parseInt(str.nextToken());
			adjList = new ArrayList[V + 1];
			key = new int[V + 1][V + 1];
			for (int i = 1; i <= V; i++) {
				adjList[i] = new ArrayList<>();
			}

			for (int i = 0; i < E; i++) {
				str = new StringTokenizer(br.readLine(), " ");
				int a = Integer.parseInt(str.nextToken());
				int b = Integer.parseInt(str.nextToken());
				int c = Integer.parseInt(str.nextToken());
				adjList[a].add(new Edge(b, c));
				adjList[b].add(new Edge(a, c));
			}

			K = Integer.parseInt(br.readLine());
			int[] start = new int[K];
			str = new StringTokenizer(br.readLine(), " ");
			for (int k = 0; k < K; k++) {
				start[k] = Integer.parseInt(str.nextToken());
			}

			for (int i = 1; i <= V; i++) {
				Collections.sort(adjList[i], new Comparator<Edge>() {

					@Override
					public int compare(Edge o1, Edge o2) {
						return Integer.compare(o1.v, o2.v);
					}

				});
			}

			for (int k = 0; k < K; k++) {
				dijkstra(start[k]);
			}

			int[] min = new int[V + 1];
			Arrays.fill(min, INF);
			int minIdx = 0;

			for (int i = 1; i <= V; i++) { // 여기가 방번호
				int result = 0;
				for (int k = 0; k < K; k++) {
					result += key[start[k]][i];
				}
				min[i] = result;
				if (min[i] < min[minIdx]) {
					minIdx = i;
				}

			}

			System.out.println(minIdx);
		}

	}

	private static void dijkstra(int i) {

		Arrays.fill(key[i], INF);
		key[i][i] = 0;

		PriorityQueue<Edge> pq = new PriorityQueue<>(new Comparator<Edge>() {
			@Override
			public int compare(Edge o1, Edge o2) {
				return Integer.compare(o1.cost, o2.cost);
			}
		});
		pq.add(new Edge(i, 0));
		while (!pq.isEmpty()) {
			Edge cur = pq.poll();
			for (int j = 0; j < adjList[cur.v].size(); j++) {
				Edge next = adjList[cur.v].get(j);
				if (key[i][next.v] > cur.cost + next.cost) {
					key[i][next.v] = cur.cost + next.cost;
					pq.add(new Edge(next.v, key[i][next.v]));
				}
			}
		}

	}

}