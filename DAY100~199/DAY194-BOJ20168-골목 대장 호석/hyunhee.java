import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
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

	static final int INF = Integer.MAX_VALUE;
	static int V, E, A, B, C;
	static ArrayList<Edge>[] adjList;
	static int MIN = Integer.MAX_VALUE;
	static boolean[] check;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		V = Integer.parseInt(str.nextToken());
		E = Integer.parseInt(str.nextToken());
		A = Integer.parseInt(str.nextToken());
		B = Integer.parseInt(str.nextToken());
		C = Integer.parseInt(str.nextToken());

		adjList = new ArrayList[V + 1];
		for (int i = 1; i <= V; i++) {
			adjList[i] = new ArrayList<>();
		}

		check = new boolean[V + 1];

		int a, b, c;
		for (int i = 0; i < E; i++) {
			str = new StringTokenizer(br.readLine(), " ");
			a = Integer.parseInt(str.nextToken());
			b = Integer.parseInt(str.nextToken());
			c = Integer.parseInt(str.nextToken());

			adjList[a].add(new Edge(b, c));
			adjList[b].add(new Edge(a, c));
		}

		int cur = A, cost = 0, maxCost = -1;
		check[cur] = true;
		dfs(cur, cost, maxCost);
		System.out.println(MIN == Integer.MAX_VALUE ? -1 : MIN);
	}

	private static void dfs(int cur, int cost, int maxCost) {

		if (cur == B) {
			MIN = Math.min(maxCost, MIN);
			return;
		}

		for (int i = 0; i < adjList[cur].size(); i++) {
			Edge next = adjList[cur].get(i);
			if (!check[next.v] && cost + next.cost <= C) {
				check[next.v] = true;
				dfs(next.v, cost + next.cost, Math.max(maxCost, next.cost));
				check[next.v] = false;
			}
		}

	}

}