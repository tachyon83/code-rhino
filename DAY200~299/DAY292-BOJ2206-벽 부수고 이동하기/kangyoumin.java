
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
//틀린이유
//제 코드의 문제점은 벽을 깬경로와 깨지않은 경로가 진행도중
//같은 노드에서 만났을때 생겼습니다. 둘중에 하나가 방문체크를 하면 
//나머지 하나의 경로는 탐색을 더하지 못하게 됩니다.
//제가 간과하였던것은 노드가 겹치더라도 벽을 뚫고온 경로와 뚫고오지
//않은경로를 구분시킬 필요가있나?하는 생각이었는데 구분을 지어줘야 하더라구요;
//5 10
//0000011000
//1101011010
//0000000010
//1111111110
//1111000000
//
//정답: 14;
//오답: -1 혹은 18;

public class Main {
	
	static int N, M;
	static int[][] arr;
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
//	[][][1]->벽이 부서진 경우 [][][0]->벽이 부서지지 않았을 때
	static boolean[][][] check;
	
	static class Place {
		int x; 
		int y;
//		이동 거리
		int dis;
//		공사 했는지
		int work;
		public Place(int x, int y, int dis, int work) {
			this.x = x;
			this.y = y;
			this.dis = dis;
			this.work = work;
		}
	}
	
	static int bfs(int x, int y) {
		Queue<Place> q = new LinkedList<>();
		q.add(new Place(x, y, 1, 0));
		check[x][y][0] = true;
		check[x][y][1] = true;
		
		while (!q.isEmpty()) {
			Place p = q.poll();
			
			if (p.x == N-1 && p.y == M-1) {
				return p.dis;
			}
			
			for(int i = 0; i < 4; i ++) {
				int _x = p.x + dx[i];
				int _y = p.y + dy[i];
				
				if(_x < 0 || _y < 0 || _x > N-1 || _y > M-1)
					continue;
//				벽이 아닐 때 -> work의 상태 그대로 가져간다
				if (arr[_x][_y] == 0 && check[_x][_y][p.work] == false) {
					check[_x][_y][p.work] = true;
					q.add(new Place(_x, _y, p.dis+1, p.work));
				}
//				벽 일때 -> work의 상태 고려
				else {
//					벽을 부순적이 없고 && 벽이 부서진 경우가 없다.
					if(p.work == 0 && check[_x][_y][1] == false) {
						check[_x][_y][1] = true;
						q.add(new Place(_x, _y, p.dis+1, 1));

					}
				}
				
			}
		}
		return -1;
	}
	
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N][M];
		check = new boolean[N][M][2];
		
		for (int i = 0; i < N; i ++) {
			String str = br.readLine();
			for (int j = 0; j < M; j ++) {
				arr[i][j] = str.charAt(j)-'0';
			}
		}
		
		System.out.println(bfs(0,0));
	}

}
