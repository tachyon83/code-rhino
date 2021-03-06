import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int map[][];
	static boolean visited[][];
	static int a[] = {1,-1,0,0};
	static int b[] = {0,0,1,-1};
	static int n;
	static int m;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map	= new int[n][m];
		visited	= new boolean[n][m];
		
		
		
		for(int i = 0 ; i < n ;i++) {
			String tmp[] = br.readLine().split(" ");
			for(int j = 0 ;j < m ;j++) {
				map[i][j] = Integer.parseInt(tmp[j]);
			}	
		}
		
		int cnt = 0 ;
		int max = 0;
		for(int i = 0 ; i < n ;i++) {
			for(int j = 0 ;j < m ;j++) {
				if(!visited[i][j] && map[i][j] ==1 ) {
					visited[i][j] = true;
					max = Math.max(max, dfs(i,j,1));
					cnt++;
					
				}
			}	
		}
		System.out.println(cnt);
		System.out.println(max);
		

	}
	
	public static int dfs(int r,int c,int cnt) {
		
		for(int i = 0 ; i < 4;i++) {
			int mr = r+a[i];
			int mc = c+b[i];
			if(mr >=0 && mc >= 0 && mr <n && mc <m) {
				if(!visited[mr][mc] && map[mr][mc] == 1) {
					visited[mr][mc] = true;
					cnt = dfs(mr,mc,cnt+1);
				}
			}
		}
		
		return cnt;
	
	}
	
}
