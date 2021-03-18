import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int[][] adj;
	static int V, E;
	static boolean[] check;
	static int[] key; // 최소 비용 저장할 배열
	static int[] pi; // 부모 노드

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		V = Integer.parseInt(str.nextToken());
		E = Integer.parseInt(str.nextToken());

		pi = new int[V]; // 정점은 0부터 시작
		key = new int[V];
		adj = new int[V][V];
		check = new boolean[V];

		for (int e = 0; e < E; e++) {
			str = new StringTokenizer(br.readLine(), " ");
			int start = Integer.parseInt(str.nextToken()) - 1;
			int end = Integer.parseInt(str.nextToken()) - 1;
			int price = Integer.parseInt(str.nextToken());
			adj[start][end] = price;
			adj[end][start] = price;
		}

		prim();

//		int result = 0, i = 0, count = 0;
		int result = 0;
//		while (i != V - 1) {
//			for (int idx = 0; idx < V; idx++) {
//				if (pi[idx] == i) {
//					result += key[idx];
//					i = idx;
//					count++;
//					break;
//				}
//			}
//			if (count > 2 * V) {
//				result = -1;
//				break;
//			}
//		}
		for (int i = 0; i < V; i++) {
			result += key[i];
		}
		System.out.println(result);

	}

	private static void prim() {
		// 1. 최소비용의 시작은 무한대
		Arrays.fill(key, Integer.MAX_VALUE);

		// 2. 시작할 임의의 정점 하나 선택
		pi[0] = -1;
		key[0] = 0;

		for (int i = 0; i < V - 1; i++) {
			int min = Integer.MAX_VALUE;
			int index = -1;
			for (int j = 0; j < V; j++) {
				if (!check[j] && key[j] < min) {
					index = j;
					min = key[j];
				}
			}

			check[index] = true; // 최소비용을 가진 정점 선택

			for (int j = 0; j < V; j++) { // 선택하지 않은 정점 중에 현재 고른 정점이랑 이어진 간선이 존재하고 이전에 저장한 key값보다 작으면 갱신
				if (!check[j] && adj[index][j] != 0 && key[j] > adj[index][j]) {
					pi[j] = index;
					key[j] = adj[index][j];
				}
			}
		}

	}

}