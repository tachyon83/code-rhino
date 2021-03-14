import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static String map[][];
	static boolean visited[][];
	static int a[] = {1,-1,0,0};
	static int b[] = {0,0,1,-1};
	static int x;
	static int y;
	static int wolf;
	static int lamb;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new  StringTokenizer(br.readLine());
		
		x = Integer.parseInt(st.nextToken());
		y = Integer.parseInt(st.nextToken());
		
		map = new String[x][y];
		visited = new boolean[x][y];
		
		for(int i = 0 ; i < x ; i++) {
			map[i] = br.readLine().split("");
		}
		
		int ansl = 0;
		int answ = 0;
		for(int i = 0 ; i < x; i++) {
			for(int j = 0 ; j < y ; j++) {
				if(!map[i][j].equals("#") && !visited[i][j]) {
					wolf = 0;
					lamb = 0;
					
					if(map[i][j].equals("v")) {
						wolf++;
					}else if(map[i][j].equals("o")) {
						lamb++;
					}
					visited[i][j] = true;
					dfs(i,j);
					
					if(wolf >= lamb) {
						answ +=wolf;
					}else {
						ansl +=lamb;
					}
					
				}
			}
		}
		
		System.out.println(ansl+" "+answ);
		
	}
	
	public static void dfs(int r, int c) {
		
		for(int i = 0 ; i < 4;i++) {
			int mr = r+a[i];
			int mc = c+b[i];
			if(mr>=0 && mc >=0 && mr <x && mc <y ) {
				if(!visited[mr][mc] && !map[mr][mc].equals("#")) {
					visited[mr][mc] = true;
					if(map[mr][mc].equals("v")){
						wolf++;
					}else if(map[mr][mc].equals("o")) {
						lamb++;
					}
					dfs(mr,mc);
				}
				
			}
			
			
		}
		
		
		
	}
	
	
	
	
}
