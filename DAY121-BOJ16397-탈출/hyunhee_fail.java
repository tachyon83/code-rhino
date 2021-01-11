import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");

		int N = Integer.parseInt(str.nextToken());
		int T = Integer.parseInt(str.nextToken());
		int G = Integer.parseInt(str.nextToken());

		boolean flag = false;

		Queue<int[]> queue = new LinkedList<>();

		queue.offer(new int[] { N, 0 });
		while (!queue.isEmpty()) {
			int[] cur = queue.poll();
			if (cur[0] == G) {
				flag = true;
				System.out.println(cur[1]);
				break;
			}
			if (cur[1] > T) {
				flag = false;
				break;
			}

			int temp = cur[0] + 1;
			queue.offer(new int[] { temp, cur[1] + 1 }); // A 누를 때
			char[] answer = (cur[0] * 2 + "").toCharArray();
			if (answer[0] == '0') {
				queue.offer(new int[] { 0, cur[1] + 1 });
			} else if (answer.length > 5) {
				continue;
			} else {
				answer[0]--;
				temp = 0;
				for (int i = 0; i < answer.length; i++) {
					temp *= 10;
					temp += (answer[i] - '0');
				}
				queue.offer(new int[] { temp, cur[1] + 1 });	// B 누를 때
			}
		}
		
		if(!flag) {
			System.out.println("ANG");
		}

	}

}
