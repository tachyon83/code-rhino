import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;


public class Main {
	
	static HashSet<String> set = new HashSet<String>();
	static int a[] = {1,-1,0,0};
	static int b[] = {0,0,1,-1};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String map[][] = new String[5][5];
		
		for(int i = 0 ; i < 5 ;i++) {
			map[i] = br.readLine().split(" ");
		}
		
		
		for(int i = 0 ; i < 5 ; i++) {
			for(int j = 0 ; j < 5; j++) {
				StringBuilder sb = new StringBuilder();
				dfs(map,0,map[i][j],i,j);
			}
		}
		
		System.out.println(set.size());
		
	}
	
	public static void dfs(String[][] map,int dept,String word,int r,int c) {
		
		if(dept == 5) {
			set.add(word);
			return ;
		}
		
		for(int i = 0 ; i < 4;i++) {
			int mr = r+a[i];
			int mc = c+b[i];
			if(mr >= 0 && mc >= 0 && mr <5 && mc < 5) {
				StringBuilder sb = new StringBuilder();
				sb.append(word);
				sb.append(map[mr][mc]);
				dfs(map,dept+1,sb.toString(),mr,mc);
			}
		}
		
		
		
	
	}
	
	
}
