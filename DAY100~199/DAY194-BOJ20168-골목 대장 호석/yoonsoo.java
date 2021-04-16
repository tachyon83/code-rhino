import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class Main {
	
	static class Node{
		int a;
		int cost;
		
		
		public Node(int a, int cost) {
			super();
			this.a = a;
			this.cost = cost;
		}
		
		
	}
	
	
	static ArrayList<Node> list[];
	static int cost[];
	static int n;
	static int cnt = 0;
	static int sum = 0;
	static boolean visited[];
	static int max = 0;
	static int ans = 0;
	static int x = 0;
	public static void main(String[] args) throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		
		visited = new boolean [n+1];
		list = new ArrayList[n+1];
		cost = new int[n+1];
	
		for(int i = 1 ; i<=n ;i++) {
			list[i] = new ArrayList<Node>();
		}
		
		
		for(int i = 0 ; i < m ;i++) {
			st = new StringTokenizer(br.readLine());
			
			int d = Integer.parseInt(st.nextToken());
			int e = Integer.parseInt(st.nextToken());
			int f = Integer.parseInt(st.nextToken());
			
			
			list[d].add(new Node(e, f));
			
		}
		
		
		
		
		visited[a]= true;
		dfs(a,b,c);
		
		
		if(x == list[a].size()) {
			System.out.println(-1);
		}else {
			
			System.out.println(ans);
		}
		
		
		
		
	

		
	}

	
	public static void dfs(int start,int end,int money) {
		
		if(start == end) {
			if(money <0) {
				x++;
				return;
			}
			
			if(sum > max) {
				max = sum;
				ans = cnt;
			}
			
			cnt = 0;
			sum = 0;
		
			return ;
		}
		
		for(int i = 0 ; i < list[start].size();i++) {
			cnt = Math.max(cnt, list[start].get(i).cost);
			sum += list[start].get(i).cost;
			
			if(!visited[list[start].get(i).a]) {
				visited[list[start].get(i).a] = true;
				dfs(list[start].get(i).a,end,money-list[start].get(i).cost);
				visited[list[start].get(i).a] = false;
			}
		}
		
		
	}
	
	
	

	
	
	
}
