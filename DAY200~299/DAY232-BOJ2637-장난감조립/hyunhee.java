package gold2.B2637;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int[][] map;
	static int[] inDegree;
	static boolean[] check;
	static ArrayList<int[]>[] al;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine()); // 1~N-1 : 중간/기본, N이 완제품 번호
		int M = Integer.parseInt(br.readLine()); // 부품간의 관계 M개 : X를 만드는 데 Y가 K개 필요

		map = new int[N + 1][N + 1];
		inDegree = new int[N + 1];
		check = new boolean[N + 1];

		al = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			al[i] = new ArrayList<>();
		}

		StringTokenizer str = null;
		int x, y, k;
		for (int i = 0; i < M; i++) {
			str = new StringTokenizer(br.readLine(), " ");
			x = Integer.parseInt(str.nextToken());
			y = Integer.parseInt(str.nextToken());
			k = Integer.parseInt(str.nextToken());
//			map[x][y] = k;
			check[x] = true;
			inDegree[x]++;
			al[y].add(new int[] { x, k });
		}

		for (int i = 1; i <= N; i++) {
			if (!check[i]) {
				System.out.println(i + " " + map[N][i]);
			}
		}

	}

	private static void topology() {
		Queue<Integer> queue = new LinkedList<>();
		int i, j;

		for (i = 1; i <= N; i++) {
			if (inDegree[i] == 0) { // 기본제품
				queue.offer(i);
				map[i][i] = 1;
			}
		}

		while (!queue.isEmpty()) {
			int x = queue.poll();

			for (i = 0; i < al[x].size(); i++) {
				int[] next = al[x].get(i);

				for (j = 1; j <= N; j++) {
					map[next[0]][j] += (next[1] * map[x][j]);
				}

				if (--inDegree[next[0]] == 0) {
					queue.offer(next[0]);
				}
			}
		}
	}

}
