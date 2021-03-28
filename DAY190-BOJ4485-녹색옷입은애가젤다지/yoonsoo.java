import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;


public class Main {
	
	
	static class Node implements Comparable<Node>{
		int row;
		int col;
		int cost;
		public Node(int row, int col, int cost) {
			super();
			this.row = row;
			this.col = col;
			this.cost = cost;
		}
		
		@Override
		public int compareTo(Node o) {
			// TODO Auto-generated method stub
			return this.cost-o.cost;
		}
		
		
	}
	
	static int map[][];
	static int arr[][];
	static int a[] = {1,-1,0,0};
	static int b[] = {0,0,1,-1};

	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String input = "";
		
		int cnt = 1;
		while(!(input = br.readLine()).equals("0") ) {
			int n = Integer.parseInt(input);
			map	= new int[n][n];
			arr = new int[n][n];
			
			for(int i = 0 ; i < n;i++) {
				String tmp[] = br.readLine().split(" ");
				for(int j = 0 ; j < n;j++) {
					map[i][j] = Integer.parseInt(tmp[j]);
					arr[i][j] =	150000;
				}
			}
			int ans = dijkstra(n);

			System.out.println("Problem "+cnt+": "+ ans);
			cnt++;
		}
		
		
	}
	
	public static int dijkstra(int n) {
		PriorityQueue<Node> pq = new PriorityQueue<Node>();
		pq.add(new Node(0, 0, arr[0][0]));
		arr[0][0] = map[0][0];
		while(!pq.isEmpty()) {
			
			int r = pq.peek().row;
			int c = pq.peek().col;
			pq.poll();
			
			for(int i = 0 ; i < 4 ; i++) {
				int mr = r+a[i];
				int mc = c+b[i];
				
				if(mr >=0 && mc >=0 && mr < n&& mc <n) {
					if(arr[mr][mc] > arr[r][c] + map[mr][mc] ) {
						arr[mr][mc] = arr[r][c] + map[mr][mc];
						pq.add(new Node(mr, mc, arr[mr][mc]));
					}
					
					
				}
				
			}
		}
		
		return arr[n-1][n-1];
		
	}
	
	
}
