package gold5.B17073;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static List<Integer>[] tree;
	static int[] water;
	static int N, W;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(str.nextToken());
		W = Integer.parseInt(str.nextToken());

		tree = new ArrayList[N + 1];
		water = new int[N + 1];
		water[1] = W;
		for (int i = 1; i <= N; i++) {
			tree[i] = new ArrayList<>();
		}

		int u, v;
		for (int i = 0; i < N - 1; i++) {
			str = new StringTokenizer(br.readLine(), " ");
			u = Integer.parseInt(str.nextToken());
			v = Integer.parseInt(str.nextToken());
			if (u > v) {
				tree[v].add(u);
			} else {
				tree[u].add(v);
			}
		}
		int root = 1;
		dfs(root);
		int P = 0;
		for (int a : water) {
			P += a;
		}
		System.out.printf("%f", P / (float) N);

	}

	private static void dfs(int root) {

		for (int i = 0; i < tree[root].size(); i++) {
			if (water[root] == 0) {
				break;
			}
			water[tree[root].get(i)]++;
			water[root]--;
		}

		for (Integer i : tree[root]) {
			if (water[i] == 0) {
				continue;
			}
			dfs(i);
		}

	}

}
