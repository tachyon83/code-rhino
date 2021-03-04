import java.io.*;
import java.util.*;

public class Main {
	static int n, m;
	static int paper[][];
	static boolean visit[][];
	
	static int max=0;
	static int a = 0;
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,-1,0,1};
	
	static int dfs(int x, int y) {
		int nx, ny;
		
		for(int i=0;i<4;i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			
			if(0<=nx && nx<m && 0<=ny && ny < n) {
				if(!visit[nx][ny] && paper[nx][ny]==1) {
					a++;
					//System.out.println("nx = "+ nx+", ny = "+ny);
					visit[nx][ny]= true;
					dfs(nx,ny);
				}
				
			}
			
		}
		
		
		return a;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		String s[] = bf.readLine().split(" ");
		n = Integer.parseInt(s[0]);
		m = Integer.parseInt(s[1]);
		
		paper  = new int[m][n];
		visit = new boolean[m][n];
		int count=0;
		
		for(int i=0;i<n;i++) {
			String s2[] = bf.readLine().split(" ");
			for(int j=0;j<m;j++) {
				paper[j][i] = Integer.parseInt(s2[j]);
			}
		}
		
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				if(paper[i][j]==1 && !visit[i][j]) {
					visit[i][j] = true;
					a=1;
					//System.out.println("visit["+i+"]["+j+"]");
					
					int area = dfs(i,j);
					if(max < area) {
						max = area;
					}
					count++;
				}
			}
		}
		
		System.out.println(count);
		
			System.out.println(max);
		
		
		

	}

}
