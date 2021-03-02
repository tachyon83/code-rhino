import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static String map[][];
	static boolean visited[][];
	static int a[] = {0,0,1,-1};
	static int b[] = {1,-1,0,0};
	static int n;
	static int m;
	static int cnt;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		visited = new boolean[m][n];
		map = new String[m][n];
		
		for(int i = 0 ; i < n ; i++) {
			map[i] = br.readLine().split("");
		}
		int w = 0;
		int b = 0;
		cnt =0;
		for(int i = 0 ; i < m; i++) {
			for(int j = 0 ; j < n;j++) {
				if(!visited[i][j]) {
					cnt = 0;
					visited[i][j] = true;
					dfs(i,j,map[i][j]);
					
					if(map[i][j].equals("W")) {
						w+= Math.pow(cnt, 2);
					}else {
						b+= Math.pow(cnt, 2);
					}
					
				}
			}
		}
		
		
		System.out.println(w+" "+b);
		
	}
	
	public static void dfs(int r,int c,String target) {
		
		cnt++;
		for(int i = 0 ;i < 4;i++) {
			int mr = r+a[i];
			int mc = c+b[i];
			
			if(mr>=0 && mc>=0 && mr<m && mc<n) {
				if(!visited[mr][mc] && map[mr][mc].equals(target)) {
					visited[mr][mc] =true;
					dfs(mr,mc,target);
				}
			}
			
			
		}

		
	}
	
}
