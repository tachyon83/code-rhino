import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N, M, result;
	static int[] condition;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// 중복 조합으로 N개의 수를 고르는데 N개의 수를 골랐을 때 조건에 부합하는지 확인해서 되면 순열 돌리고 아니면 다른 조합 확인
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(str.nextToken());
		M = Integer.parseInt(str.nextToken());
		condition = new int[M];
		str = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < M; i++) {
			condition[i] = Integer.parseInt(str.nextToken());
		}

		combi(0);

		System.out.println(result);
	}

	static int[] check = new int[10];

	private static void combi(int cnt) {
		if (cnt == N) {
			for (int i = 0; i < M; i++) {
				if (check[condition[i]] == 0) {
					return;
				}
			}
			result++;
			return;
		}

		for (int i = 0; i < 10; i++) {
			check[i]++;
			combi(cnt + 1);
			check[i]--;
		}
	}
}