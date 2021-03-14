import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int map[][];
	static boolean alpha[];
	static int a[] = {1,1,0,0};
	static int b[] = {0,0,1,-1};
	static int ans = 0;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		alpha = new boolean[26];
		map = new int[r][c];
		
		for(int i = 0 ; i <r  ;i++) {
			String tmp[] = br.readLine().split("");
			for(int j = 0 ; j < tmp.length;j++) {
				map[i][j] = tmp[j].codePointAt(0)-65;
			}
		}
		
		alpha[map[0][0]] = true;
		dfs(0,0,r,c,1);
		
		System.out.println(ans);

	}
	
	public static void dfs(int r, int c,int x,int y,int cnt) {
		boolean flag = false;
		
		for(int i = 0 ; i < 4 ; i++) {
			int mr = r+a[i];
			int mc = c+b[i];

			if(mr>=0 && mc>=0 && mr <x && mc <y) {
				int num = map[mr][mc];
				
				if(!alpha[num]) {
					alpha[num] = true;
					dfs(mr,mc,x,y,cnt+1);
					alpha[num] = false;
					flag =true;
				}
			}
		}
		if(!flag) {
			ans = Math.max(ans, cnt);
			return;
		}
	
	
	}
}
