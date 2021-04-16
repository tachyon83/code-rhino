import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static List<Integer>[] list;
	static boolean[] check;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");

		N = Integer.parseInt(str.nextToken());
		M = Integer.parseInt(str.nextToken());

		list = new ArrayList[N];
		check = new boolean[N];
		for (int i = 0; i < N; i++) {
			list[i] = new ArrayList<>();
		}

		for (int m = 0; m < M; m++) {
			str = new StringTokenizer(br.readLine(), " ");
			int A = Integer.parseInt(str.nextToken());
			int B = Integer.parseInt(str.nextToken());
			list[A].add(B);
			list[B].add(A);
		}
		for (int i = 0; i < N; i++) {
			check[i] = true;
			if (dfs(i, 1)) {
				System.out.println(1);
				return;
			}
			check[i] = false;
		}
		System.out.println(0);
	}

	private static boolean dfs(int start, int cnt) {
		if (cnt == 5) {
			return true;
		}
		for (int i = 0; i < list[start].size(); i++) {
			int temp = list[start].get(i);
			if (!check[temp]) {
				check[temp] = true;
				if (dfs(temp, cnt + 1)) {
					return true;
				}
				check[temp] = false;
			}
		}
		return false;
	}

}