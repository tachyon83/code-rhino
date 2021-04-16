import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
	
	static int map[][];
	static boolean visited[][];
	static ArrayList<int[]> list = new ArrayList<int[]>();
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		map = new int[9][9];
		visited = new boolean[9][9];
		
		for(int i = 0 ; i < 9 ;i++) {
			String tmp[] = br.readLine().split(" ");
			for(int j = 0 ; j < tmp.length; j++) {
				map[i][j] = Integer.parseInt(tmp[j]);
				if(map[i][j] == 0) {
					list.add(new int[] {i,j});
				}
			}
		}
		
		back(0,0);
		
		
	}
	static boolean flag = false;
	public static void back(int cur,int cnt) {
		if(cnt == list.size()) {
			for(int i = 0 ; i < 9 ;i++) {
				for(int j = 0 ; j < 9; j++) {
					System.out.print(map[i][j]+" ");
				}
				System.out.println();
			}
			flag = true;
			return;
		}
        
		if(flag)return;
		
		
		
		
		int r = list.get(cur)[0];
		int c = list.get(cur)[1];
		
		for(int i = 1 ; i <= 9 ; i++) {
			if(chk(r,c,i)) {
				map[r][c] = i;
				back(cur+1,cnt+1);
				map[r][c] = 0;
			}
		}


	}
	
	public static boolean chk(int r,int c,int value) {
		//가로
		for(int i = 0; i < 9 ;i++) {
			if(map[r][i] == value) {
				return false;
			}
		}
		//세로
		for(int i = 0; i < 9 ;i++) {
			if(map[i][c] == value) {
				return false;
			}
		}
		
		int mr = r/3*3;
		int mc = c/3*3;
		
		for(int i = 0 ; i < 3;i++) {
			for(int j = 0 ; j <3;j++) {
				if(map[mr+i][mc+j] == value) {
					return false;
				}
			}
		}
		
		
		
		
		return true;
	}
	
	
	
}
