import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

	static int S;
	static boolean[][] check; // check[모니터값][클립보드값]
	static int MIN = 1000;

	static class Point {
		int count;
		int emoji;
		int clipBoard;

		public Point(int count, int emoji, int clipBoard) {
			this.count = count;
			this.emoji = emoji;
			this.clipBoard = clipBoard;
		}

		@Override
		public String toString() {
			return "Point [count=" + count + ", emoji=" + emoji + ", clipBoard=" + clipBoard + "]";
		}

	}

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		S = Integer.parseInt(br.readLine());
		check = new boolean[1001][1001];
		bfs();
		bw.write(MIN + "");
		bw.flush();

	}

	private static void bfs() {

		Queue<Point> queue = new LinkedList<>();
		queue.offer(new Point(0, 1, 0)); // count, emoji, clipBoard
		check[1][0] = true;

		while (!queue.isEmpty()) {
			Point cur = queue.poll();
			if (cur.emoji == S) {
				MIN = Math.min(MIN, cur.count);
				continue;
			}

			// 1. 클립보드에 복사
			int nextClip = cur.emoji;
			if (cur.count < MIN && !check[cur.emoji][nextClip]) {
				check[cur.emoji][nextClip] = true;
				Point nextP = new Point(cur.count + 1, cur.emoji, nextClip);
				queue.offer(nextP);
			}

			// 2. 클립보드 내용 붙이기
			int nextEmoji = cur.emoji + cur.clipBoard;
			if (nextEmoji <= 1000 && cur.clipBoard > 0 && cur.count < MIN && !check[nextEmoji][cur.clipBoard]) {
				check[nextEmoji][cur.clipBoard] = true;
				Point nextP = new Point(cur.count + 1, nextEmoji, cur.clipBoard);
				queue.offer(nextP);
			}

			// 3. 화면 내용 삭제
			nextEmoji = cur.emoji - 1;
			if (cur.count < MIN && nextEmoji >= 0 && !check[nextEmoji][cur.clipBoard]) {
				check[nextEmoji][cur.clipBoard] = true;
				Point nextP = new Point(cur.count + 1, nextEmoji, cur.clipBoard);
				queue.offer(nextP);
			}

		}

	}

}