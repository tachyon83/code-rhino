import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int arr[][];
	static int n;
	static int INF = 10000000;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		StringTokenizer st= new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		arr = new int[n+1][n+1];
		
	
		
		for(int i = 0 ; i < k ;i++) {
			st= new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			arr[a][b] = -1;
			arr[b][a] = 1;
		}

		
		floyd();
		
		int s = Integer.parseInt(br.readLine());
		
		for(int i = 0 ;i < s; i++) {
			st= new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			System.out.println(arr[a][b]);
		}
		

		
		
		
		
	}
	
	public static void floyd() {
		
		for(int i = 1 ;i <= n ; i++ ) {
			for(int j = 1 ; j <= n ;j++) {
				for(int k = 1 ; k <= n;k++) {
					if(i == j||j==k|| k==i)continue;
						
					
						if(arr[j][k] == 0) {
							arr[j][k] = arr[j][i] == arr[i][k] ? arr[j][i] : 0;
						}
					
				}
			}
		}
		
		
	}
	
	
	
}
