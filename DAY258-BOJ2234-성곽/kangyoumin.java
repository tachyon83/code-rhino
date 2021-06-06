

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


class Room {
	int x;
	int y;
	
	public Room (int x, int y) {
		this.x = x;
		this.y = y;

	}
}

public class Main {
//	서북동남
	static int[] dx = {0, -1, 0, 1};
	static int[] dy = {-1, 0, 1, 0};
	static int n, m, max = 0, roomNum = 0, size = 1;
	static HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();	
	static boolean[][] visit;
	static int[][] arr;

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
				if(!visit[i][j]) {
					roomNum++;
					bfs1(i, j, roomNum);
					map.put(roomNum, size);
				}	
			}
		}
//		방의 개수
		System.out.println(roomNum);
//		방의 최대넓이
		System.out.println(max);
		max = 0;
		
//		벽을 뚫을 때 
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				visit = new boolean[i][j];
				bfs2(i, j);
			}
		}
		System.out.println(max);
		
	}
	
	static void bfs1 (int x, int y, int roomNum) {
		Queue<Room> q = new LinkedList<Room>();
		q.add(new Room(x, y));
		visit[x][y] = true;
		size = 1;

		while(!q.isEmpty()) {
			Room room = q.poll();
			int val = arr[room.x][room.y];
//			룸 넘버로 바꿔주기
			arr[room.x][room.y] = roomNum;
//			서북동남에 벽이 있는지 없는지 0001, 0010, 0100, 1000
			int[] wall = {val & (1<<0), val & (1<<1), val & (1<<2), val & (1<<3)};
			for(int i = 0; i < 4; i++) {
				int _x = room.x + dx[i];
				int _y = room.y + dy[i];
				if(_x < 0 || _y < 0 || _x >= m || _y >= n) continue;
//				벽이 있다
				if(visit[_x][_y] || wall[i] != 0) continue; 
				
				q.add(new Room(_x, _y));
				visit[_x][_y] = true;
				size++;
				
			}
		}
		max = Math.max(max, size);
	}
	
	static void bfs2(int x, int y) {
		int thisRoom = arr[x][y];
		for(int i = 0; i < 4; i++) {
			int _x = x + dx[i];
			int _y = y + dy[i];
			if(_x < 0 || _y < 0 || _x >= m || _y >= n) continue;
			
			int thatRoom = arr[_x][_y];
			if(thisRoom == thatRoom) continue;
			else max = Math.max(max, map.get(thisRoom) + map.get(thatRoom));
		}
	}
	
}
