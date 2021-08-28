package gold2.B2252;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int N, M;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(str.nextToken());
		M = Integer.parseInt(str.nextToken());
		List<Integer> list = new ArrayList<>();

		int a, b, aIdx, bIdx;

		for (int i = 0; i < M; i++) {
			str = new StringTokenizer(br.readLine(), " ");
			a = Integer.parseInt(str.nextToken());
			b = Integer.parseInt(str.nextToken());
			if (list.contains(a) && list.contains(b)) {
				aIdx = list.indexOf(a);
				bIdx = list.indexOf(b);
				if (aIdx < bIdx) {
					continue;
				}

			}

		}

	}

}
