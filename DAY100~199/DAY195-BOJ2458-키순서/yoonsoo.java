import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	static boolean arr[][];
	static int n;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		arr = new boolean[n+1][n+1];
		

		
		
		for(int i = 0 ; i < m ; i++) {
			st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			arr[a][b] = true;
		}
		
		
		floyd();
		

		
		int cnt[] = new int[n+1];
		for(int i = 1 ; i <=n ; i++) {
			for(int j = 1; j <=n;j++) {
				if(arr[i][j] ) {
					cnt[i] +=1;
					cnt[j] +=1;
				}
				
			}
		}
		
		int ans = 0;
		for(int num : cnt) {
			if(num == n-1) {
				ans++;
			}
		}
		
		
		System.out.println(ans);
		
		
	}
	
	public static void floyd() {
		 // 기준이 되는 거쳐가는 노드 i
		for(int i = 1 ; i <=n ; i++) {
			// 출발하는 노드 j
			for(int j = 1; j <=n;j++) {
				// 도착하는 노드 k
				for(int k = 1 ; k <=n;k++) {
					if(arr[j][i] && arr[i][k] ) {
						arr[j][k] = true;
					}
				}
			}
		}
		
		
	}
	
}
