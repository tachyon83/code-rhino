//아직 하는 중 ㅠㅠ
import java.io.*;
import java.util.*;


public class Main {
	static int map[][] ;
	static boolean visit[][];
	static HashSet <Integer> hash;
	
	
	static int[] ax = {1,0,-1,0};
	static int[] ay = {0,-1,0,1};
	
	
	static void dfs(int x, int y, int five, int res) {
		
		if(five == 5) {
			hash.add(res);
			System.out.println("hash input == "+res+"\n");
			return;
		}
		
		for(int i=0;i<4;i++) {
			int nx = x + ax[i];
			int ny = y + ay[i];
			
			
			if(0<=nx && nx <5 && 0<=ny && ny<5 ) {
					res = res * 10 + map[nx][ny];
					System.out.println("five = "+five +"; nx = "+ nx+", ny = "+ny+", res ="+res);
					dfs(nx, ny, five+1, res);
					
			}
		}
	}

	
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		//sb = new StringBuilder();

		map = new int [5][5];
		
		
		for(int i=0;i<5;i++) {
			String s[] = bf.readLine().split(" ");
			for(int j=0;j<5;j++) {
				map[i][j] = Integer.parseInt(s[j]);
			}
		}
		
	
		hash = new HashSet<>();
		
		
	
		for(int i=0;i<1;i++) {
			for(int j=0;j<1;j++) {
				System.out.println("\ndfs 시작 ; i = "+i+", j = "+j+", res= "+map[i][j]);
				
				dfs(i,j, 0, map[i][j]);
				
			}
		}
		
		System.out.println(hash.size());

	}

}
