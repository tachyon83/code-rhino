import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int K = Integer.parseInt(br.readLine());
		int[] arr = new int[(int) Math.pow(2, K)];
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		for (int i = 1; i < arr.length; i++) {
			arr[i] = Integer.parseInt(str.nextToken());
		}

		boolean[] check = new boolean[arr.length];
		check[0] = true;

		StringBuilder sb = new StringBuilder();
		int root = arr.length / 2;

		Queue<Integer> queue = new LinkedList<>();
		queue.offer(root);
		check[root] = true;

		int cnt = root;

		while (!queue.isEmpty()) {
			int size = queue.size();
			cnt /= 2;
			for (int i = 0; i < size; i++) {
				int parent = queue.poll();
				sb.append(arr[parent] + " ");
				if (parent - cnt > 0 && !check[parent - cnt]) {
					check[parent - cnt] = true;
					queue.offer(parent - cnt);
				}
				if (parent + cnt < arr.length && !check[parent + cnt]) {
					check[parent + cnt] = true;
					queue.offer(parent + cnt);
				}
			}
			sb.append("\n");
		}

		System.out.println(sb.toString());
	}

}