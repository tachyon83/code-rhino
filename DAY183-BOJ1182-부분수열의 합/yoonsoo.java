import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int n;
	static boolean visited[];
	static int arr[];
	static int cnt = 0;
	static int s;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		s = Integer.parseInt(st.nextToken());
		arr = new int[n];
		
		String tmp[] = br.readLine().split(" ");
		for(int i = 0 ; i < n;i++) {
			arr[i] = Integer.parseInt(tmp[i]);
		}
		
		
		for(int i = 1 ; i <= n;i++) {
			visited = new boolean[n];
			combi(i,0);
		}
		
		
		System.out.println(cnt);

	}
	
	
	public static void combi(int depth,int start) {
		if(depth == 0) {
			int sum = 0;
			for(int i = 0 ; i < n; i++) {
				if(visited[i]) {
					sum+=arr[i];
				}
			}
			
			if(sum == s)cnt++;
		}
		
		for(int i = start ; i < n;i++) {
			if(!visited[i]) {
				visited[i] = true;
				combi(depth-1,i+1);
				visited[i] = false;
			}
		}
		
		
	}
	
	
	
}
