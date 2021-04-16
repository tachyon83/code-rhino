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
		int dis;

		Node(int a, int dis){
			this.a = a;

			this.dis = dis;
		}
	}
	
	
	static Node arr[];
	static ArrayList<Node>[] list;
	static int distance[];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		
		int v = Integer.parseInt(st.nextToken());
		int e = Integer.parseInt(st.nextToken());
		
		int start = Integer.parseInt(br.readLine());
		
		arr = new Node[v+1];
		distance = new int[v+1];
		list = new ArrayList[v+1];
		
		for(int i = 1 ; i <= v ;i ++) {
			list[i] = new ArrayList<Node>();
		}

		for(int i = 0 ; i < e; i++) {
			st = new StringTokenizer(br.readLine());

			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			
			list[a].add(new Node(b, c));
		}
		
		
		Arrays.fill(distance, Integer.MAX_VALUE);
		djikstra(start);
		
		for(int i = 1 ; i <=v;i++) {
			System.out.println(distance[i] == Integer.MAX_VALUE ? "INF" : distance[i]);

		}

	}
	
	public static void djikstra(int start) {
		PriorityQueue<Node> pq = new PriorityQueue<Node>(new Comparator<Node>() {

			@Override
			public int compare(Node o1, Node o2) {
				// TODO Auto-generated method stub
				return o1.dis-o2.dis;
			}
		});
		pq.add(new Node(start, 0));
		distance[start]=0;
		
		while(!pq.isEmpty()) {
			int now = pq.peek().a;
			int dis = pq.peek().dis;
			pq.poll();

			if(distance[now] <dis) continue;
			
			for(int i = 0 ; i < list[now].size();i++) {
				
				int next = list[now].get(i).a;
				int nextplus = list[now].get(i).dis+dis;
				
				if(distance[next] >nextplus) {
					distance[next] = nextplus;
					pq.add(new Node(next, nextplus));
				}
				
			}
			
		}
	}
	
	
}
