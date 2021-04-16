//어렵구만 ! 


import java.io.*;
import java.util.*;

public class Main {
	static int n, m;
	static int[][] dist;
	static boolean[][] visit;

	static class Pair {
		int s;
		int c;

		Pair(int s, int c) {
			this.s = s;
			this.c = c;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		n = Integer.parseInt(bf.readLine());
		dist = new int[1001][1001];	//걸리는 시간
		visit = new boolean[1001][1001];

		Queue<Pair> q = new LinkedList<>();

		for (int i = 1; i <= n; i++) {
			Arrays.fill(dist[i], -1);
		}

		q.add(new Pair(1, 0));
		dist[1][0] = 0;

		while (!q.isEmpty()) {
			int s = q.peek().s; //이모티콘 수
			int c = q.peek().c;	//클립보드에 있는 임티 수
			
			
			q.poll();
			
			// 복사하는 경우
			if (dist[s][s] == -1) {

				q.add(new Pair(s, s));
				
				dist[s][s] = dist[s][c] + 1;
			}
			// 붙여넣기하는경우
			if (s + c <= n && dist[s + c][c] == -1) {
				q.add(new Pair(s + c, c));
				
				dist[s + c][c] = dist[s][c] + 1;
				
			}

			// 삭제하는 경우
			if (s - 1 >= 0 && dist[s - 1][c] == -1) {
				
					q.add(new Pair(s - 1, c));
					
					dist[s - 1][c] = dist[s][c] + 1;
				}
			}
		

		int ans = -1;

		for (int i = 0; i <= n; i++) {

			if (dist[n][i] != -1) // -1이 아닌 최솟값을 구한다.
			{
				if (ans == -1 || ans > dist[n][i])
					ans = dist[n][i];
			}
		}

		System.out.println(ans);

	}

}
