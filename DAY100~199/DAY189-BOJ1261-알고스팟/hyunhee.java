import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static class Edge implements Comparable<Edge> {
		int r;
		int c;
		int price;

		public Edge(int r, int c, int price) {
			this.r = r;
			this.c = c;
			this.price = price;
		}

		@Override
		public int compareTo(Edge o) {
			return Integer.compare(this.price, o.price);
		}

		@Override
		public String toString() {
			return "Edge [r=" + r + ", c=" + c + ", price=" + price + "]";
		}

	}

	static int[][] key;
	static int R, C;
	static int[][] adj;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		C = Integer.parseInt(str.nextToken());
		R = Integer.parseInt(str.nextToken());
		adj = new int[R][C];
		key = new int[R][C];
		for (int i = 0; i < R; i++) {
			char[] input = br.readLine().toCharArray();
			for (int j = 0; j < C; j++) {
				adj[i][j] = input[j] - '0';
			}
		}

		System.out.println(dijkstra(0, 0));

	}

	static final int INF = Integer.MAX_VALUE;
	static int[][] dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

	private static int dijkstra(int r, int c) {
		for (int i = 0; i < R; i++) {
			Arrays.fill(key[i], INF);
		}
		key[r][c] = 0;
		PriorityQueue<Edge> pq = new PriorityQueue<>();
		pq.add(new Edge(r, c, 0));
		while (!pq.isEmpty()) {
			Edge cur = pq.poll();

			for (int d = 0; d < dirs.length; d++) {
				int nr = cur.r + dirs[d][0];
				int nc = cur.c + dirs[d][1];
				if (isIn(nr, nc) && key[nr][nc] > cur.price + adj[nr][nc]) {
					key[nr][nc] = cur.price + adj[nr][nc];
					pq.add(new Edge(nr, nc, key[nr][nc]));
				}
			}

		}

		return key[R - 1][C - 1];
	}

	private static boolean isIn(int r, int c) {
		return r >= 0 && r < R && c >= 0 && c < C;
	}

}