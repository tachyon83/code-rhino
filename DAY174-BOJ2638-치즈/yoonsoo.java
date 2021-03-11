import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	
	static int[][] map;
	static ArrayList<int[]> contect;
	static int a[] = {1,-1,0,0};
	static int b[] = {0,0,1,-1};
	static boolean visited[][];
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		map = new int[n][m];
		for(int i = 0 ; i < n ; i++) {
			for(int j = 0 ; j < m ; j++) {
				map[i][j] =sc.nextInt();
			}
		}
		
		
		// 가장자리는 무조건 치즈가 아니다
		// 가장자리를 dfs돌려서 치즈내부 공간을 찾는다.
		
		// 여기부터 반복
		int ans = 0;
		while(true){
			ans ++;
			visited = new boolean[n][m];
			contect = new ArrayList<int[]>();
			dfs(0,0,n,m,0);
			if(!visited[0][m-1]) {
				dfs(0,m-1,n,m,0);	
			}
			for(int i = 0 ; i < n ; i++) {
				for(int j = 0 ; j < m ; j++) {
					if(!visited[i][j]) {
						if(map[i][j] == 1) {
							dfs(i,j,n,m,1);
						}
					}
				}
			}
			
			for(int i = 0 ; i < contect.size(); i++) {
				int tmp[] = contect.get(i);
				map[tmp[0]][tmp[1]] = 0;
			}
			
			if(allmelt(n,m)) {
				break;
			}
		}
		

		System.out.println(ans);
		
		
		
	}
	
	public static void dfs(int x,int y,int n,int m,int target) {
		
		
		visited[x][y] = true;
		int cnt = 0;
		for(int i = 0 ;i < 4 ; i++) {
			int dx = x+a[i];
			int dy = y+b[i];
			if(target == 1) {
				
				if(dx>=0 && dx<n && dy>=0 && dy<m ) {
					if(map[dx][dy]== target  && visited[dx][dy] == false) {
						dfs(dx,dy,n,m,1);
					}else if(map[dx][dy] == 0 && visited[dx][dy]) {
						cnt++;
					}
				}
			}else if(target == 0 ) {
				if(dx>=0 && dx<n && dy>=0 && dy<m && visited[dx][dy] == false) {
					if(map[dx][dy]== target) {
						
						dfs(dx,dy,n,m,0);
					}
				}
			}
			
		}
		
		
		if(cnt >=2) {
			contect.add(new int[] {x,y});
		}
		
		
	}
	
	public static boolean allmelt(int n,int m) {
		for(int i = 0 ; i <n ; i++) {
			for(int j = 0 ;j < m ; j++) {
				if(map[i][j] == 1) {
					return false;
				}
			}
		}
		return true;
	}
	
	
	
}
