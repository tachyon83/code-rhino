import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int[] inDegree, time, result;
	static ArrayList<Integer>[] al;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = null;
		N = Integer.parseInt(br.readLine()); // 작업 개수
		al = new ArrayList[N + 1];
		inDegree = new int[N + 1];
		time = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			al[i] = new ArrayList<>();
		}

		for (int i = 1; i <= N; i++) { // N개의 줄
			str = new StringTokenizer(br.readLine(), " ");
			time[i] = Integer.parseInt(str.nextToken());
			int J = Integer.parseInt(str.nextToken());
			for (int j = 0; j < J; j++) {
				al[Integer.parseInt(str.nextToken())].add(i);
				++inDegree[i];
			}
		}

		result = new int[N + 1];
		System.out.println(topolgySort());
	}

	private static int topolgySort() {

//		1. 진입차수가 0인것 담아
		Queue<Integer> queue = new LinkedList<Integer>();
		for (int i = 1; i <= N; i++) {
			result[i] = time[i];
			if (inDegree[i] == 0) {
				queue.offer(i);
			}
		}

//		2. 간선을 하나씩 빼면서 진입차수 업뎃하고 0되는 애들 담아
		while (!queue.isEmpty()) {
			int cur = queue.poll();
			for (int i = 0; i < al[cur].size(); i++) {
				int next = al[cur].get(i);
				result[next] = Math.max(result[next], result[cur] + time[next]);
				if (--inDegree[next] == 0) {
					queue.offer(next);
				}
			}
		}

//		결과는 하나
		Arrays.sort(result);
		return result[N];

	}

}