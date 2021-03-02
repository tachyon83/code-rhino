//아직 실패
//bfs 더 공부하고 
import java.io.*;
import java.util.*;

public class Main {
	static int n, m, v;
	static int map[][];

	static void update() {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (i == j || j == k || k == i) {
						continue;
					}
					if (map[i][k] != 10001 && map[k][j] != 10001) {

						map[i][j] = Math.min(map[i][k] + map[k][j], map[i][j]);
						map[j][i] = map[i][j];
					}

				}
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		String[] s = bf.readLine().split(" ");
		n = Integer.parseInt(s[0]); // 정점의 개수
		m = Integer.parseInt(s[1]); // 간선의 개수
		v = Integer.parseInt(s[2]); //탐색을 시작할 정점의 번호

		map = new int[n][m];
		for (int i = 0; i < n; i++) {
			Arrays.fill(map[i], 10001);
			map[i][i] = 0;
		}

		for (int i = 0; i < n-1; i++) {
			String s2[] = bf.readLine().split(" ");
			int a = Integer.parseInt(s2[0]);
			int b = Integer.parseInt(s2[1]);
			int c = Integer.parseInt(s2[2]);
			map[a-1][b-1] = c;
			map[b-1][a-1] = map[a-1][b-1];

		}
		// System.out.println();

		update();

		for (int i = 0; i < m; i++) {
			String s3[] = bf.readLine().split(" ");
			int a = Integer.parseInt(s3[0]);
			int b = Integer.parseInt(s3[1]);

			sb.append(map[a-1][b-1] + "\n");
		}

		System.out.print(sb);
	}

}
