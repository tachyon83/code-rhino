import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	
	static ArrayList<Integer> list[];
	static boolean visited[];
	static int level[];
	static int ans = 0;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		
		int n = Integer.parseInt(st.nextToken());
		int s = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		
		list = new ArrayList[n+1];
		visited = new boolean[n+1];
		level = new int[n+1];
		
		for(int i = 1 ; i <= n;i++) {
			list[i] = new ArrayList<Integer>();
		}
		for(int i = 0 ; i < n-1;i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			list[a].add(b);
			list[b].add(a);
		}
		visited[s] = true;
		dfs(s,1);
		visited = new boolean[n+1];
		bfs(s, d);
//		System.out.println(Arrays.toString(level));
		System.out.println(ans);
	}
	
	public static int dfs(int num,int lev) {
		
		int curlevel = lev;
		
		for(int i = 0 ; i < list[num].size();i++) {
			if(!visited[list[num].get(i)]) {
				visited[list[num].get(i)] = true;
				curlevel = Math.max(curlevel , dfs(list[num].get(i),lev+1));
			}
		}
		level[num] = curlevel - lev;
		
		return curlevel;
	}
	
	public static void bfs(int s,int d) {
		Queue<Integer> que = new LinkedList<Integer>();
		
		que.add(s);
		visited[s] = true;
		while(!que.isEmpty()) {
			int cur = que.poll();
			
			for(int i = 0 ; i < list[cur].size();i++) {
				int next = list[cur].get(i);
				if(visited[next] || level[next] <d)continue;
				visited[next] = true;
				ans +=2;
				que.add(next);
				
			}
			
		}
		
	}
	
	
}
