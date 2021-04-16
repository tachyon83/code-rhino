import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class Main {
	
	static class node implements Comparable<node>{
		int num;
		int plus;
		
		
		public node(int num, int plus) {
			super();
			this.num = num;
			this.plus = plus;
		}


		@Override
		public int compareTo(node o) {
			// TODO Auto-generated method stub
			return plus-o.plus;
		}
		
	}
	
	static ArrayList<node> list[];
	static int distance[];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int x = Integer.parseInt(st.nextToken());
		
		list = new ArrayList[n+1];
		distance = new int[n+1];
		
		
		for(int i = 1 ; i <= n ; i++) {
			list[i] = new ArrayList<node>();
		}
		
		for(int i = 0 ; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			
			list[a].add(new node(b, c));
		}
		int sum[] = new int[n+1];
		
		for(int i = 1; i <= n;i++) {
			if(i == x) continue;
			Arrays.fill(distance, Integer.MAX_VALUE);
			dijkstra(i);
			sum[i] += distance[x];
//			System.out.println(Arrays.toString(distance));
		}
		Arrays.fill(distance, Integer.MAX_VALUE);
		dijkstra(x);

		int max = 0;
		for(int i = 1; i <= n;i++) {
			if(i == x)continue;

			sum[i] += distance[i];
			max = Math.max(sum[i], max);
		}
		
		System.out.println(max);
		
	}
	
	public static void dijkstra(int start) {
		PriorityQueue<node> pq = new PriorityQueue<node>();
		distance[start] = 0;
		pq.add(new node(start, 0));
		
		while(!pq.isEmpty()) {
			int cur = pq.peek().num;
			int plus = pq.peek().plus;
			
			pq.poll();
			
			//최단거리가 아닌경우
			if(distance[cur] > plus) continue;
			
			for(int i = 0 ;i < list[cur].size();i++) {
				int next = list[cur].get(i).num;
				// 선택된 노드를 인접 노드로 거쳐서 가는 비용
				int nextplus = plus+list[cur].get(i).plus;
				
				if(distance[next] > nextplus) {
					distance[next] = nextplus;
					pq.add(new node(next, nextplus));						
					
				}
				
				
			}
			
		}
		
		
	}
	
	
	
}
