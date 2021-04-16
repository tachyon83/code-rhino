import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	static int arr[][];
	static int n;
	static int INF = 1000000000;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		arr = new int[n+1][n+1];
		
		
		for(int i = 1 ; i <= n ;i++) {
			for(int j = 1 ; j <=n;j++) {
				if(i==j)continue;
				arr[i][j] = INF;
			}
		}
		
		
		for(int i = 0 ; i < m ;i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			arr[a][b]= Math.min(arr[a][b] , 1);
			arr[b][a]= Math.min(arr[b][a] , 1);
		}
		
		floyd();
		
		int ansa = 0;
		int ansb= 0 ;
		int min = Integer.MAX_VALUE;
		for(int i = 1 ; i < n;i++) {
			for(int j = i+1 ; j <=n ;j++) {
				int sum = 0;
				for(int k = 1 ; k <=n ;k++ ) {
					sum += Math.min(arr[i][k], arr[j][k]);
				}
				if(sum < min) {
					min = sum;
					ansa = i;
					ansb = j;
						
					
				}
				
				
			}
		}
		System.out.println(ansa+" "+ansb+" "+ min*2);

		
		
	}
	
	public static void floyd() {
		
		for(int i = 1 ; i <= n;i++) {
			for(int j = 1; j <= n;j++) {
				for(int k = 1 ; k<= n ;k++) {
					if(arr[i][j] == INF || arr[i][k] == INF) continue;
					arr[j][k] = Math.min(arr[j][k],  arr[j][i] + arr[i][k]);
					
				}
			}
		}
		
		
	}
	
	
	
	
	
}
