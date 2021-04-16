import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static boolean visited[];
	static int ans = 0;
	static int n;
	static int m;
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		visited = new boolean[10];
		
		String tmp[] = br.readLine().split(" ");
		
		for(int i = 0 ;i < m;i++) {
			visited[Integer.parseInt(tmp[i])] = true;
		}
		
		combi(0,0);
		
		System.out.println(ans);
	}
	
	
	public static void combi(int depth,int cnt) {
		if(depth == n ) {
			if(cnt != m)return;
			ans++;
			return;
			
		}
		
		for(int i = 0 ; i < 10 ;i++) {
			if(visited[i]) {
				visited[i] = false;
				combi(depth+1,cnt+1);
				visited[i] = true;
				continue;
			}
			combi(depth+1,cnt);
		}
		
		
	}
	
	
}
