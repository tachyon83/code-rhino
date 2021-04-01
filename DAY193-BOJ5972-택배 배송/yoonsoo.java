import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	
	static class Node {
		int a;
		int cost;
		public Node(int a, int cost) {
			super();
			this.a = a;
			this.cost = cost;
		}
		

	
	}
	
	
	static List<Node> list[];
	static int cost[];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		cost = new int[n+1];
		list = new ArrayList[n+1];
		
		for(int i = 1 ; i <=n;i++) {
			list[i] = new ArrayList<Node>();
		}
		
		
		
		for(int i = 0 ; i < m ;i++) {
			st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			
			
			list[a].add(new Node(b, c));
			list[b].add(new Node(a, c));
		}
		
		Arrays.fill(cost, Integer.MAX_VALUE);
		dijkstra(1);
		
		System.out.println(cost[n]);
	}
	
	public static void dijkstra(int start) {
		PriorityQueue<Node> pq = new PriorityQueue<Node>(new Comparator<Node>() {

			@Override
			public int compare(Node o1, Node o2) {
				// TODO Auto-generated method stub
				return Integer.compare(o1.cost, o2.cost);
			}
		});
		
		
		pq.add(new Node(start, 0));
		cost[start] = 0;
		
		
		while(!pq.isEmpty()) {
			Node cur = pq.poll();

			
			if(cost[cur.a] < cur.cost) continue;
			
			for(int i = 0 ;i < list[cur.a].size();i++) {
				int next = list[cur.a].get(i).a;
				int nextcost = list[cur.a].get(i).cost;
				
				if(cost[next] > cur.cost+nextcost) {
					cost[next] = cur.cost+nextcost;
					pq.add(new Node(next, cost[next]));
				}
				
				
			}
			
			
			
		}
		
		
	}
	
	
	
	
}
