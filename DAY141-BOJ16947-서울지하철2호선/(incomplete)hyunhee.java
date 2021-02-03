package gold3.B16947;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static List<Integer>[] graph;
	static boolean[] check; // 순환역인치 check 0 : 방문X 1 : 방문O 2: 재귀로 순환함=순환역
	static List<Integer> cycle = new ArrayList<>();
	static Queue<int[]> queue = new LinkedList<>();

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		graph = new ArrayList[N];
		for (int n = 0; n < N; n++) {
			graph[n] = new ArrayList<>();
		}

		for (int n = 0; n < N; n++) {
			StringTokenizer str = new StringTokenizer(br.readLine(), " ");
			int a = Integer.parseInt(str.nextToken()) - 1;
			int b = Integer.parseInt(str.nextToken()) - 1;
			graph[a].add(b);
			graph[b].add(a);
		} // end input

		// 1. 순환역 찾기
		for (int n = 0; n < N; n++) {
			check = new boolean[N];
			check[n] = true;
			dfs(n, n, 0);
			check[n] = false;
		}

		StringBuilder sb = new StringBuilder();
		// 2. 순환역까지 거리 구하기
		for (int n = 0; n < N; n++) { // queue[0] : 위치, [1] : 거리
			sb.append(bfs(n)).append(" ");
		}
		System.out.println(sb);

	}

	private static int bfs(int start) {
		queue.clear();
		check = new boolean[N];
		check[start] = true;
		queue.offer(new int[] { start, 0 });
		while (!queue.isEmpty()) {
			int[] cur = queue.poll();
			if (cycle.contains(cur[0])) {
				return cur[1];
			}
			for (int i = 0; i < graph[cur[0]].size(); i++) {
				int temp = graph[cur[0]].get(i);
				if (!check[temp]) {
					check[temp] = true;
					queue.offer(new int[] { temp, cur[1] + 1 });
				}
			}
		}
		return -1;
	}

	private static void dfs(int start, int end, int len) {
		if (cycle.contains(start)) {
			return;
		}

		for (int i = 0; i < graph[end].size(); i++) {
			int temp = graph[end].get(i);
			if (temp == start && len > 1) {
				cycle.add(start);
				return;
			}
			if (!check[temp]) {
				check[temp] = true;
				dfs(start, temp, len + 1);
				check[temp] = false;
			}
		}

	}

}
