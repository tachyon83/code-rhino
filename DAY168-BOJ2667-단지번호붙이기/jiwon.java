import java.io.*;
import java.util.*;

public class Main {
	static int n;
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
			
			if(0<=nx && nx<n && 0<=ny && ny < n) {
				if(!visit[nx][ny] && paper[nx][ny]==1) {
					a++;
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

		
		n = Integer.parseInt(bf.readLine());
		
		
		paper  = new int[n][n];
		visit = new boolean[n][n];
		int complex[] = new int[n*n];
		int count=0;
		
		for(int i=0;i<n;i++) {
			String s2[] = bf.readLine().split("");
			for(int j=0;j<n;j++) {
				paper[i][j] = Integer.parseInt(s2[j]);
			}
		}
		int number = 0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(paper[i][j]==1 && !visit[i][j]) {
					visit[i][j] = true;
					a=1;
					//System.out.println("visit["+i+"]["+j+"]");
					complex[number++] = dfs(i,j);
					count++;
				}
			}
		}
		
		System.out.println(count);
		Arrays.parallelSort(complex);
		for(int i : complex) {
			if(i==0) {
				continue;
			}
			System.out.println(i);
		}
		

	}

}
