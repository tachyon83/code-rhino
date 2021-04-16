import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {

	static int[] parent;
	static List<Integer>[] map;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		int N = Integer.parseInt(str.nextToken());
		int M = Integer.parseInt(str.nextToken());

		parent = new int[N + 1];
		map = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			map[i] = new ArrayList<>();
		}
		for (int n = 1; n <= N; n++) {
			parent[n] = n;
		}
		for (int m = 0; m < M; m++) {
			str = new StringTokenizer(br.readLine(), " ");
			int a = Integer.parseInt(str.nextToken());
			int b = Integer.parseInt(str.nextToken());
			map[a].add(b);
			map[b].add(a);
		} // 입력 끝 UF 시작

		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < map[i].size(); j++) {
				unionParent(i, map[i].get(j));
			}
		}

		TreeSet<Integer> ts = new TreeSet<>();
		for (int n = 1; n <= N; n++) {
			ts.add(parent[n]);
		}

		System.out.println(ts.size());
	}

	private static int findParent(int x) {
		if (parent[x] == x) { // 조상노드
			return x;
		}
		return parent[x] = findParent(parent[x]);
	}

	private static int unionParent(int x, int y) {
		x = findParent(x);
		y = findParent(y);

		if (x < y) { // 노드가 작은 게 부모
			return parent[y] = x;
		} else {
			return parent[x] = y;
		}

	}

}