import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	
	static ArrayList<Integer> list[];
	static int chk[];
	static boolean visited[];
	static int cnt = 0;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		double w = Double.parseDouble(st.nextToken());
		//물을 담아야할 공간
	
		list = new ArrayList[n+1];
		visited	= new boolean[n+1];
		
		//방법.2
		chk	= new int[n+1];
		
		
		for(int i = 1 ; i <=n ;i++) {
			list[i] = new ArrayList<Integer>();
		}
		
		for(int i = 0 ; i < n-1;i++) {
			st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			list[a].add(b);
			list[b].add(a);	
			
			//방법.2 리프노드 개수만 체크
			chk[a]++;
			chk[b]++;
			
		}
		
		//방법.2 리프노드 개수만 체크 1은 루트노드이므로 1은 제외
		for(int i = 2 ; i <= n;i++) {
			if(chk[i] == 1) {
				System.out.println(i);
				cnt++;
			}
		}
		
		
		visited[1] = true;
//		dfs(1);
		System.out.printf("%.10f",w/cnt);
		
		
	}
	
	public static void dfs(int start) {
		
		boolean flag = true;

		
		for(int i = 0 ;i < list[start].size();i++) {
			int next = list[start].get(i);
			if(!visited[next]) {
				flag = false;
				visited[next] = true;
				dfs(next);
			}
		}
		
		if(flag) {

			cnt++;
		}
	
		
	}
	
}
