import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

import java.util.StringTokenizer;


public class review {
	
	static class Node{
		int a;
		int b;
		int cost;
		
		public Node(int a,int b, int cost) {
			super();
			this.a = a;
			this.b = b;
			this.cost = cost;
		}
		
	}
	
	static ArrayList<Node> list;
	static long[] upper;
	static int n;
	static int m;
	static int e;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		int s = Integer.parseInt(st.nextToken());
		e = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		
		list = new ArrayList<Node>();
			
		Node[] node = new Node[m];
		
		for(int i = 0 ; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			
			node[i] = new Node(a, b, cost);
		
		
		}


		
		upper = new long[n];
		
		String[] max = br.readLine().split(" ");
		
		for(int i = 0 ; i < m ;i++) {
			int min = Integer.parseInt(max[node[i].b])-node[i].cost;
			
			list.add(i, new Node(node[i].a, node[i].b, min));
		}
		
		
		if(bellmanford(s,max)) {
			
			
			System.out.println(upper[e]);
				
			
			
		}

	
		
	}
	
	
    // 최단 거리를 찾아 upper에 저장 후 true 리턴
    // 하지만, 음수 싸이클이 존재하면 false 리턴
	public static boolean bellmanford(int start,String max[]) {
		Arrays.fill(upper, Long.MIN_VALUE);
		upper[start] = Integer.parseInt(max[start]);
		//upper[i] : 정점 i까지의 최단 거리의 상한
		
		
		
		for(int i = 0 ; i < n+m ;i++) {
			for(int j = 0; j <m ;j++) {
				int a = list.get(j).a;
				int b = list.get(j).b;
				int cost = list.get(j).cost;
				
				if(upper[a] == Long.MIN_VALUE) {
					continue;
				
				}else if(upper[a] == Long.MAX_VALUE) {
		
					upper[b] = Long.MAX_VALUE;
				}else if( upper[a]+cost > upper[b]) {
					
					upper[b] = upper[a]+cost;

					if(i >= n-1) {
				
						upper[b] = Long.MAX_VALUE;
					}
						
				
						
				}
				
				
				
			}
			
		}
		


		if(upper[e] == Long.MIN_VALUE) {
			System.out.println("gg");
			return false;
		}else if (upper[e] == Long.MAX_VALUE) {
			System.out.println("Gee");
			return false;
		}else {
			return true;
		}
		

		
	}
	

	
	
	
	
}
