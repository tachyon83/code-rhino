
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static class node{
		int nodenum;
		int distance;
		
		public node(int nodenum, int distance) {
			super();
			this.nodenum = nodenum;
			this.distance = distance;
		}
		
	}
	
	
	static ArrayList<node> map[];
	static boolean visited[];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		map = new ArrayList[n+1];

		for(int i = 0 ; i <= n;i++) {
			map[i] = new ArrayList<node>();
		}
		


		for(int i = 0 ; i < n-1;i++) {
			st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			
			map[a].add(new node(b, c));
			map[b].add(new node(a, c));

			
		}
		for(int i = 0 ; i < m ;i++) {
			visited = new boolean[n+1];
			
			st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			bfs(a,b);
		}
		
		
		
	}

	public static void bfs(int now,int end) {
		Queue<node> que = new LinkedList<node>();
		
		que.add(new node(now, 0));
		
		int sum = 0;
		while(!que.isEmpty()) {
			int num	 = que.peek().nodenum;
			int distance = que.peek().distance;
			visited[num] = true;
			que.poll();
			for(int i = 0 ; i < map[num].size();i++) {
				int next = map[num].get(i).nodenum;
				int nextdistance = map[num].get(i).distance;
				
				if(next == end) {
					System.out.println(distance+nextdistance);
					break;
				}else if(next !=num  && !visited[next]){

					que.add(new node(next, distance+nextdistance));
					
					
				}
				
				
			}
		}

		
	}

}
