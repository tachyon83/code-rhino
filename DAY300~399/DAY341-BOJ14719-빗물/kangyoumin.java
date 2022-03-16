import java.io.*;
import java.util.*;

public class Main {

	static int[] map;
	static int ret, left, right;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int H = Integer.parseInt(st.nextToken());
		int W = Integer.parseInt(st.nextToken());
		map = new int[W];
		ret = left = right = 0;

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < W; i++) {
			int N = Integer.parseInt(st.nextToken());
			map[i] = N;
		}

		// 모이는 빗물 계산
		for (int i = 1; i < W - 1; i++) {
			left = right = 0;
			for (int j = 0; j < i; j++) {
				left = Math.max(map[j], left);
			}
			for (int j = i + 1; j < W; j++) {
				right = Math.max(map[j], right);
			}
			if (map[i] < left && map[i] < right) {
				ret += Math.min(left, right) - map[i];
			}
		}
		System.out.println(ret);
	}
}
