import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static class Node{
		int a;
		int b;
		int cost;
		
		
		
		public Node(int a, int b, int cost) {
			super();
			this.a = a;
			this.b = b;
			this.cost = cost;
		}
		
		
		
	}
	
	
	static Node[] list;
	static int p;
	static int f;
	static int c;
	static int d;
	static int cost[];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		d = Integer.parseInt(st.nextToken()); //한도시에서 벌수있는돈
		p = Integer.parseInt(st.nextToken()); // 도시를 연결하는 단방향 경로
		c = Integer.parseInt(st.nextToken()); // 도시 개수 1부터
		f = Integer.parseInt(st.nextToken()); // 제트기 노선 개수
		int s = Integer.parseInt(st.nextToken()); // 제트기 비용
		cost = new int[c+1];
		
		list = new Node[p+f];
		
		for(int i = 0 ; i < p ;i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			list[i] = new Node(a, b, 0);
		}
		
		
		for(int i = p ; i < p+f ; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			
			list[i] = new Node(a, b, -cost);
			
		}
		
		bellmanfort(s);

		
		
	}
	public static void bellmanfort(int start) {
		Arrays.fill(cost, Integer.MIN_VALUE);
		cost[start] = d;
		
		for(int i = 0 ; i < c;i++) {
			for(int j = 0 ; j <f+p;j++) {
				
				int cur = list[j].a;
				int next = list[j].b;
				int getcost = list[j].cost;
				
				if(cost[cur] != Integer.MIN_VALUE&&cost[cur]+getcost+d > cost[next]) {
					
					cost[next] = cost[cur]+getcost+d;
					if(i == c-1) {
						System.out.println("-1");
						return ;
					}
					
				}
				
				
			}
			
		}
		

		
		int max =0;
		for(int i = 0 ; i < cost.length;i++) {
			max = Math.max(cost[i], max);
		}
		System.out.println(max);
		
		
	}
	
	
	
	
	
}
