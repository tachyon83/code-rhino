
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static ArrayList<Integer> list[];
	static boolean visited[];
	static int cnt = 0;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		
		
		
		for(int i = 0 ; i < t; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			list = new ArrayList[n+1];
			visited = new boolean[n+1];
			cnt = 0;
			for(int j = 1 ; j <= n;j++) {
				list[j] = new ArrayList();
			}
			for(int j = 0 ; j < m;j++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				list[a].add(b);
				list[b].add(a);
			}
			
			bfs(1);
			System.out.println(cnt);
			
		}
		
		
	}
	
	public static void bfs(int start) {
		Queue<Integer> que = new LinkedList<Integer>();
		visited[start] = true;
		que.add(start);
		
		while(!que.isEmpty()) {
			int cur = que.poll();
		
			for(int i = 0 ; i< list[cur].size();i++) {
				int next = list[cur].get(i);
				if(!visited[next]) {
					cnt++;
					visited[next] = true;
					que.add(next);
				}
				
			}
			
			
		}
		
		
	}
	
	
	
}
