
import java.io.*;
import java.util.*;

public class Main {
	static int n, m;
	static String map [][];
	static boolean visit[][];
	static int[] dx = {0,-1,0,1};
	static int[] dy = {1,0,-1,0};
	static int count  = 1;
	
	static void dfs(int x, int y, String color) {
		visit[x][y] = true;
		int nx, ny;
		
		for(int i=0;i<4;i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			
			if(0<=nx && nx < n && 0<=ny && ny < m) {
				if(!visit[nx][ny] && map[nx][ny].equals(color)) {
					count++;
					dfs(nx, ny, color);
				}
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb2 = new StringBuilder();

		String[] s = bf.readLine().split(" ");
		n = Integer.parseInt(s[0]);
		m = Integer.parseInt(s[1]);
		
		map = new String[n][m];
		visit = new boolean[n][m];
		
		for(int i=0;i<m;i++) {
			String s2[] = bf.readLine().split("");
			for(int j=0;j<n;j++) {
				map[j][i] = s2[j];
			}
		}
		int ours=0, others=0;
		
		//아군 카운트
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(!visit[i][j] && map[i][j].equals("W")) {
					
					dfs(i,j,"W");
					//System.out.println("count="+count);
					ours += Math.pow(count, 2);
					count = 1;
				}
			}
		}
		
		//System.out.println("count="+count);
		count = 1;
		//적군 카운트
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(!visit[i][j] && map[i][j].equals("B")) {
					dfs(i,j,"B");
					//System.out.println("count="+count);
					others += Math.pow(count, 2);
					count = 1;
				}
			}
		}

		System.out.println(ours + " "+ others);
		
	}
	

}
