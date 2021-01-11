import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

//	static final int MAX = 100000;
	static Queue<int[]> queue = new LinkedList<>();
	static boolean[] check = new boolean[100000];

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");

		int N = Integer.parseInt(str.nextToken());
		int T = Integer.parseInt(str.nextToken());
		int G = Integer.parseInt(str.nextToken());
		int answer = -1;
		queue.offer(new int[] { N, 0 });
		while (!queue.isEmpty()) {
			int[] p = queue.poll();
			if (p[1] > T) {
				break;
			}
			if (p[0] == G) {
				answer = p[1];
				break;
			}
			if (p[0] < 99999) {
				Abutton(p[0], p[1]);
			}
			if (p[0] * 2 < 99999) {
				Bbutton(p[0], p[1]);
			}
		}

		System.out.println(answer == -1 ? "ANG" : answer);

	}

	private static void Bbutton(int number, int cnt) {
		number *= 2;
		String temp = "";
		while (number > 9) {
			temp = (number % 10) + temp;
			number /= 10;
		}
		temp = (number - 1) + temp;
		number = Integer.parseInt(temp);
		if (number >= 0 && !check[number]) {
			queue.offer(new int[] { number, cnt + 1 });
		}

	}

	private static void Abutton(int number, int cnt) {
		if (!check[number + 1]) {
			check[number + 1] = true;
			queue.offer(new int[] { number + 1, cnt + 1 });
		}
	}

}