import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	static int n;
	static int map[];
	static boolean rowchk[];
	static int ans;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		ans = 0;
		// 열을 기준으로 돌릴거임
		// 행의 위치 중복을 체크할 배열
		// map[i]에 들어가는 값들은 행의 index값 i는 열의 위치의미
		// 처음에는 0,0~ 7,0까지 dfs 진행
		
		for(int i = 0 ; i < n ;i++) {
			map = new int[n];
			Arrays.fill(map, 9);
			
			
			map[0] = i;

			dfs(0);
			
		}
		System.out.println(ans);
		
		
	}
	
	public static void dfs(int col) {
		if(col == n-1 ) {
	
			ans++;

			return;
			
		}
		
		
		// 행을 반복 해야함
		for(int i = 0 ;i < n ; i++) {

			//i가 행이 되는것 
			map[col+1] = i; 
			if(chk(col+1) ) {	

				dfs(col+1);
				
			}
		}
		
		
	}
	
	//현재 열의 위치
	public static boolean chk(int col) {
		if(map[col] == -1) return false;
		
		for(int i = 0 ; i < col; i++) {
			
			if(map[col] == map[i]) {
				return false;
			}

			if(Math.abs(map[col] - map[i]) == Math.abs(col-i) ) {
				
				return false;
			}
		}
		
		
		return true;
	}
		
	
}
