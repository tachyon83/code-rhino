import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int[] map = new int[101];
	static boolean[] check = new boolean[101];

	static class Point {
		int cur; // 현재 위치
		int count; // 주사위 굴린 횟수

		public Point(int cur, int count) {
			this.cur = cur;
			this.count = count;
		}

	}

	static Queue<Point> queue = new LinkedList<>();

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		int N = Integer.parseInt(str.nextToken());
		int M = Integer.parseInt(str.nextToken());
		for (int n = 0; n < N; n++) {
			str = new StringTokenizer(br.readLine());
			map[Integer.parseInt(str.nextToken())] = Integer.parseInt(str.nextToken());
		}

		for (int m = 0; m < M; m++) {
			str = new StringTokenizer(br.readLine());
			map[Integer.parseInt(str.nextToken())] = Integer.parseInt(str.nextToken());
		}

		check[1] = true;
		int cur = 1;
		if (map[1] > 0) {
			cur = map[1];
			check[cur] = true;
		}

		queue.offer(new Point(cur, 0));
		System.out.println(bfs());

	}

	private static int bfs() {

		while (!queue.isEmpty()) {
			Point now = queue.poll();
			if (now.cur == 100) {
				return now.count;
			}
			for (int i = 1; i <= 6; i++) {
				int next = now.cur + i;
				if (next <= 100 && !check[next]) {
					check[next] = true;
					if (map[next] > 0) {
						next = map[next];
						check[next] = true;
					}
					queue.offer(new Point(next, now.count + 1));
				}
			}
		}

		return -1;
	}

}