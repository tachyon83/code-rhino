import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Main {

	static List<Integer>[] friends;
	static boolean[] check;
	static int max = -1;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		friends = new ArrayList[N];

		for (int i = 0; i < N; i++) {
			friends[i] = new ArrayList<>();
			char[] input = br.readLine().toCharArray();
			for (int j = 0; j < N; j++) {
				if (input[j] == 'Y') {
					friends[i].add(j);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			check = new boolean[N];
			bfs(i);
		}

		System.out.println(max);

	}

	private static void bfs(int start) {

		Queue<int[]> queue = new LinkedList<int[]>();
		check[start] = true;
		queue.offer(new int[] { start, 0 });
		int count = 0;
		int[] friend = queue.poll();

		for (int i = 0; i < friends[friend[0]].size(); i++) {
			int _f = friends[friend[0]].get(i);
			if (!check[_f]) {
				check[_f] = true;
				queue.offer(new int[] { _f, friend[0] + 1 });
				count++;
			}
		}

		while (!queue.isEmpty()) {
			friend = queue.poll();
			for (int i = 0; i < friends[friend[0]].size(); i++) {
				int _f = friends[friend[0]].get(i);
				if (!check[_f]) {
					check[_f] = true;
					count++;
				}
			}
		}

		max = Math.max(max, count);
	}

}