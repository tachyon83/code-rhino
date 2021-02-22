import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static List<Integer>[] adjList;
	static boolean[] check;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		adjList = new ArrayList[N + 1];
		check = new boolean[N + 1];
		for (int i = 1; i <= N; i++) {
			adjList[i] = new ArrayList<Integer>();
		}

		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		int A = Integer.parseInt(str.nextToken());
		int B = Integer.parseInt(str.nextToken());

		int M = Integer.parseInt(br.readLine());

		while (M-- > 0) {
			str = new StringTokenizer(br.readLine(), " ");
			int a = Integer.parseInt(str.nextToken());
			int b = Integer.parseInt(str.nextToken());
			adjList[a].add(b);
			adjList[b].add(a);
		}

		System.out.println(bfs(A, B));

	}

	private static int bfs(int a, int b) {

		Queue<int[]> queue = new LinkedList<int[]>();
		queue.offer(new int[] { a, 0 });
		check[a] = true;
		while (!queue.isEmpty()) {
			int[] cur = queue.poll();
			for (int i = 0; i < adjList[cur[0]].size(); i++) {
				int next = adjList[cur[0]].get(i);
				if (next == b) {
					return cur[1] + 1;
				}
				if (!check[next]) {
					check[next] = true;
					queue.offer(new int[] { next, cur[1] + 1 });
				}
			}
		}

		return -1;

	}

}