import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static ArrayList<Integer> arr[];
	static boolean visited[];
	static int ans[];
	public static void main(String[] args) throws  IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		arr = new ArrayList[n+1];
		visited = new boolean [n+1];
		ans = new int[n+1];
		
		for(int i = 1 ; i <=n; i++) {
			arr[i] = new ArrayList<Integer>();
		}
		
		for(int i = 0 ; i < n-1 ; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			arr[a].add(b);
			arr[b].add(a);
		}
		
		bfs();
		for(int i = 2 ; i <=n;i++) {
			
			System.out.println(ans[i]);
		}

	}
	
	public static void bfs() {
		Queue<Integer> que = new LinkedList<Integer>();
		que.add(1);
		
		while(!que.isEmpty()) {
			int num = que.poll();
			visited[num] = true;
			for(int g : arr[num]) {
				if(!visited[g]) {
					ans[g] = num;
					que.add(g);
				}
			}
			
		}
		
	}
	
	
	public static void dfs(int target) {
		if(visited[target])return;
		
		visited[target] = true;
		for(int num : arr[target]) {
			if(!visited[num]) {
				ans[num] = target;
				dfs(num);
			}
		}
		
		
		
	}
	
	
}
