package gold4.B16397;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int T;
	static int G;
	static final int INF = Integer.MAX_VALUE;
	static int answer = INF;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");

		int N = Integer.parseInt(str.nextToken());
		T = Integer.parseInt(str.nextToken());
		G = Integer.parseInt(str.nextToken());
		dfs(N, 0);
		System.out.println(answer == INF ? "ANG" : answer);
	}

	private static void dfs(int cur, int cnt) {
		if (cnt >= answer) {
			return;
		}
		if (cur == G) {
			answer = Math.min(answer, cnt);
			return;
		}
		if (cnt == T) {
			return;
		}
		if (cur < 99999) {
			dfs(cur + 1, cnt + 1);
		}
		if ((cur * 2) >= 100000) {
			return;
		}
		char[] temp = (cur * 2 + "").toCharArray();
		if (temp[0] > '0') {
			temp[0]--;
		}
		int number = 0;
		for (int i = 0; i < temp.length; i++) {
			number *= 10;
			number += (temp[i] - '0');
		}
		dfs(number, cnt + 1);
	}

}
