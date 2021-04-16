import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
	
	static int n;
	static int map[][];
	static boolean visited[][];
	static int a[] = {1,-1,0,0};
	static int b[] = {0,0,-1,1};
	
	public static void main(String[] args) throws  IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		map	= new int[n][n];
		visited = new boolean[n][n];

		for(int i = 0 ; i < n;i++) {
			String tmp[] = br.readLine().split("");
			for(int j = 0 ; j <n;j++) {
				map[i][j] = Integer.parseInt(tmp[j]);
			}
		}
		
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int i = 0 ; i < n;i++) {
			for(int j = 0 ; j <n;j++) {
				if(map[i][j] == 1 && !visited[i][j]) {
					visited[i][j] = true;
					list.add(dfs(i,j,1));
				}
			
			}
		}
		
		System.out.println(list.size());
		list.sort(null);
		for(int i:list) {
			System.out.println(i);
		}
		
		
	}
	
	public static int dfs(int r,int c,int cnt) {
		
		for(int i = 0 ; i < 4 ;i++) {
			int mr = r + a[i];
			int mc = c + b[i];
			if(mr >=0 && mc >= 0 && mr <n && mc<n) {
				if(!visited[mr][mc] && map[mr][mc] == 1) {
					visited[mr][mc] = true;
					cnt = dfs(mr,mc,cnt+1);
				}
			}
			
		}
		return cnt;
	}
	
	
	
}
