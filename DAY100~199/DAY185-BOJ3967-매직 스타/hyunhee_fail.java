package gold5.B3967;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class Main {

	static char[][] map;
	static boolean[] check; // 12개 'A' ~ 'L'
	static int[][] checkPoint = { { 0, 4 }, { 1, 1 }, { 1, 3 }, { 1, 5 }, { 1, 7 }, { 2, 2 }, { 2, 6 }, { 3, 1 },
			{ 3, 3 }, { 3, 5 }, { 3, 7 }, { 4, 4 } };
	static List<Integer>[] lines;
	static int[] sum;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		check = new boolean[12];
		map = new char[8][8];
		sum = new int[6];
		lines = new ArrayList[12];
		for(int i=0;i<12;i++) {
			lines[i] = new ArrayList<>();	// 각 정점에서 확인해야하는 선의 위치
		}
		
		int cnt = 0;

		for (int i = 0; i < 8; i++) {
			map[i] = br.readLine().toCharArray();
			for (int j = 0; j < 8; j++) {
				if (map[i][j] == '.' || map[i][j] == 'x') {
					continue;
				}
				check[map[i][j] - 'A'] = true;
				cnt++;
			}
		}

		dfs();

	}

	private static void dfs() {

		for (int i = 0; i < checkPoint.length; i++) {
			int[] point = checkPoint[i];
			if (map[point[0]][point[1]] == 'x') {
				
			}
		}

	}

}
