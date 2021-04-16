import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

	static int[] parents;
	static int[] rank;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		while (true) {
			StringTokenizer str = new StringTokenizer(br.readLine(), " ");
			int V = Integer.parseInt(str.nextToken());
			int E = Integer.parseInt(str.nextToken());
			if (V == 0 && E == 0) {
				break;
			}
			parents = new int[V];
			rank = new int[V];
			int[][] edges = new int[E][3];
			for (int i = 0; i < E; i++) {
				str = new StringTokenizer(br.readLine(), " ");
				for (int j = 0; j < 3; j++) {
					edges[i][j] = Integer.parseInt(str.nextToken());
				}
			}

			Arrays.sort(edges, new Comparator<int[]>() {

				@Override
				public int compare(int[] o1, int[] o2) {
					return Integer.compare(o1[2], o2[2]);
				}

			});

			for (int i = 0; i < V; i++) {
				makeSet(i);
			}

			int cnt = 0;
			int result = 0;
			for (int i = 0; i < E; i++) {
				int a = findSet(edges[i][0]);
				int b = findSet(edges[i][1]);

				if (a == b) { // 같은 그룹이면 continue
					continue;
				} else { // 다른 그룹이면 연결
					union(a, b);
					result += edges[i][2];
					cnt++;
					if (cnt == V - 1) {
						break;
					}
				}
			}
			for (int i = 0; i < E; i++) {
				result -= edges[i][2];
			}
			System.out.println(-result);
		}

	}

	private static void makeSet(int x) {
		parents[x] = x;
	}

	private static int findSet(int x) {
		if (x == parents[x]) {
			return x;
		} else {
			parents[x] = findSet(parents[x]);
			return parents[x];
		}
	}

	private static void union(int x, int y) {
		int px = findSet(x);
		int py = findSet(y);
		if (rank[px] > rank[py]) {
			parents[py] = px;
		} else {
			parents[px] = py;
			if (rank[px] == rank[py]) {
				rank[py]++;
			}
		}
	}

}