import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	static class Node implements Comparable<Node>{
		int a;
	
		int cost;
		
		public Node(int a,  int cost) {
			super();
			this.a = a;
			this.cost = cost;
		}

		@Override
		public int compareTo(Node o) {
			// TODO Auto-generated method stub
			return this.cost-o.cost;
		}
	
		
	}
	
	static int num[];
	static ArrayList<Node> list[];
	static int sum[];
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		int t = Integer.parseInt(br.readLine());
		for(int i = 0 ; i < t;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
		
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			
		
			
			list = new ArrayList[n+1];
			num = new int[n+1];
			for(int j = 0 ; j <= n ;j++) {
				list[j] = new ArrayList<Node>();
			}
			
			
			for(int j = 0 ; j < m ;j++) {
				st = new StringTokenizer(br.readLine());
				
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());
				
			
				list[a].add(new Node(b, c));	
				list[b].add(new Node(a, c));
			}
			
			int k = Integer.parseInt(br.readLine());
			
			String tmp[] = br.readLine().split(" ");
			int mem[] = new int[k];
			for(int j = 0 ; j < k; j++) {
				mem[j] = Integer.parseInt(tmp[j]);
			}
			
			
			//다익스트라 돌리기
			sum = new int[n+1];
			int ans = Integer.MAX_VALUE;
			int idx = 1;
			
			for(int j = 0 ; j < mem.length ;j++) {
				

				dijkstra(mem[j]);
	
				
				for(int z = 1 ; z <= n ;z++) {
					sum[z] +=num[z];
				}

			}
			
			for(int j = 1 ; j <= n;j++) {
				if(ans>sum[j]) {
					ans = sum[j];
					idx = j;
				}
			}
			
		
			System.out.println(idx);

			
			
		}

		
		
		
	}
	public static void dijkstra(int start) {
		Arrays.fill(num,  Integer.MAX_VALUE);
		PriorityQueue<Node> pq = new PriorityQueue<Node>();
		pq.add(new Node(start, 0));
		num[start] = 0;
		
		while(!pq.isEmpty()) {
			int cur = pq.peek().a;
			int cost = pq.peek().cost;
			pq.poll();
			
			if(num[cur] < cost ) continue;
			
			for(int i = 0 ; i < list[cur].size();i++) {
				int next = list[cur].get(i).a;
				int nextcost = list[cur].get(i).cost;
				
				if(num[next] > nextcost+cost) {
					num[next] = nextcost+cost;
					pq.add(new Node(next, num[next]));
				}
			}
		}
		

		
	}
	
	
	
	
	
}
