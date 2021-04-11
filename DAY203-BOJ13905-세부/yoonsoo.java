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
	static int dis[];
	static int ans = Integer.MAX_VALUE;
	static boolean visited[];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		
		int s = Integer.parseInt(st.nextToken());
		int e = Integer.parseInt(st.nextToken());
		
		dis = new int[n+1];
		visited = new boolean[n+1];
		list = new ArrayList[n+1];
		
		for(int i = 1 ; i <=n ;i++) {
			list[i] = new ArrayList<Node>();
		}
		
		
		for(int i = 0 ; i < m;i++) {
			st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());

			list[a].add(new Node(b, cost));
			list[b].add(new Node(a, cost));
			
		}
		
		djikstra(s);
		System.out.println(Arrays.toString(dis));
		System.out.println(dis[e]);
		
		

		
	}
	
	public static void djikstra(int start) {
		
		dis[start] = Integer.MAX_VALUE;
		PriorityQueue<Node> pq = new PriorityQueue<Node>(new Comparator<Node>() {

			@Override
			public int compare(Node o1, Node o2) {
				// TODO Auto-generated method stub
				return o2.cost-o1.cost;
			}
		});
		pq.add(new Node(start, 0));
		
		
		while(!pq.isEmpty()) {
			int cur = pq.peek().a;
			int cost = pq.peek().cost;
			pq.poll();
			
			if(visited[cur])continue;
			visited[cur] = true;
	
			
			for(int i = 0 ;i < list[cur].size();i++) {
				int next = list[cur].get(i).a;
				int nextcost = list[cur].get(i).cost;
				
				dis[next] = Math.max(dis[next], Math.min(dis[cur], nextcost) );
				pq.add( list[cur].get(i) );
				
			}
		}
	}
	
	

	
}
