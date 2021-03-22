import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, S, answer;
	static int[] arr;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");

		N = Integer.parseInt(str.nextToken());
		S = Integer.parseInt(str.nextToken());

		arr = new int[N];
		str = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(str.nextToken());
		}

		int sum = 0, count = 0, cur = 0;
		for (int i = 1; i <= N; i++) {
			test(sum, count, cur, i);
		}

		System.out.println(answer);

	}

	private static void test(int sum, int count, int cur, int s) {
		if (count == s) {
			answer = sum == S ? answer + 1 : answer;
			return;
		}

		for (int i = cur; i < N; i++) {
			test(sum + arr[i], count + 1, i + 1, s);
		}
	}

}