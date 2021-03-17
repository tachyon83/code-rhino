import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	static class Node implements Comparable<Node>{
		int a;
		int dis;
		
		
		public Node(int a,int dis) {
			super();
			this.a = a;
			this.dis = dis;
		}


		@Override
		public int compareTo(Node o) {
			// TODO Auto-generated method stub
			return dis-o.dis;
		}
	
	}
	
	
	
	static int distance[];
	static ArrayList<Node> list[];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int e = Integer.parseInt(st.nextToken());
		
		distance = new int[n+1];
		list = new ArrayList[n+1];
		for(int i = 1; i <= n;i++) {
			list[i] = new ArrayList<Node>();
		}
		
		
		for(int i = 0 ; i < e; i++) {
			 st = new StringTokenizer(br.readLine());
				
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			list[a].add(new Node(b, c));
			list[b].add(new Node(a, c));
		}
		
		st = new StringTokenizer(br.readLine());
		int v1 = Integer.parseInt(st.nextToken());
		int v2 = Integer.parseInt(st.nextToken());
		
		if( e== 0) {
			System.out.println(-1);
		}else {
			
			int sum1 = 0;
			int sum2 = 0;
			
			dijkstra(1);
			sum1+=distance[v1];
			sum2+=distance[v2];
			
			dijkstra(v1);
			sum1 +=distance[v2];
			sum2 +=distance[n];
			
			dijkstra(v2);
			sum2 +=distance[v1];
			sum1+=distance[n];
			
			
			System.out.println(Math.min(sum1, sum2));
		}
		
		
		
	}
	public static void dijkstra(int start) {
		Arrays.fill(distance, Integer.MAX_VALUE);
		PriorityQueue<Node> pq = new PriorityQueue<Node>();
		distance[start] = 0;
		pq.add(new Node(start, 0));
		
		
		while(!pq.isEmpty()) {
			int cur = pq.peek().a;
			int dis = pq.peek().dis;
			pq.poll();
			
			if(distance[cur] < dis) continue;
			
			for(int i = 0 ; i < list[cur].size();i++) {
				int next = list[cur].get(i).a;
				int nextplus = list[cur].get(i).dis;
				
				if(distance[next] > dis+nextplus) {
					distance[next] = dis+nextplus;
					pq.add(new Node(next, dis+nextplus));
				}
				
			}
			
		}
		
	}

	
}
