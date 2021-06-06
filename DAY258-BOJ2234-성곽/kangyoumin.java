
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


class Room {
	int x;
	int y;
//	방 사이즈
	int size;
//	벽을 제거할지 말지
	boolean remove;
	
	public Room (int x, int y, int size, boolean remove) {
		this.x = x;
		this.y = y;
		this.size = size;
		this.remove = remove;
	}
}

public class Main {
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	static int n, m;

	static boolean[][] visit;
	static int[][] arr;
	static ArrayList<Integer> list = new ArrayList<Integer>();

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[m][n];
		visit = new boolean[m][n];
		for(int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < n; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
//				둘다 true가 아닐때!
				if(!visit[i][j]) {
					bfs(i, j);
				}	
			}
		}
		
	}
	
	static void bfs (int x, int y) {
		Queue<Room> q = new LinkedList<Room>();
		q.add(new Room(x, y, 1, false));
		visit[x][y] = true;

		while(!q.isEmpty()) {
			Room room = q.poll();
			for(int i = 0; i < 4; i++) {
				int _x = room.x + dx[i];
				int _y = room.y + dy[i];
				if(visit[_x][_y] || _x < 0 || _y > 0 || _x >= n || _y >= m) continue;
//				벽이 없을 때
				if(!isWall(room.x, room.y, dx[i], dy[i])) {
					q.add(new Room(x, y, ++room.size, false));
					visit[x][y] = true;
				}
//				벽이 있을 때				
				else {
					
				}

				
				
			}
		}
		
	}
	static boolean isWall (int x, int y, int Dx, int Dy) {
		return true;
	}

}
