import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	static int arr[][];
	static int a[] = new int[] {1,-1,0,0};
	static int b[] = new int[] {0,0,-1,1};
	static int n;
	static int m;
	static boolean visited[][];
	
	static class point  implements Comparable<point>{
		int r;
		int c;
		int cnt;
		
		
		
		public point(int r, int c, int cnt) {
			super();
			this.r = r;
			this.c = c;
			this.cnt = cnt;
		}



		@Override
		public int compareTo(point o) {
			// TODO Auto-generated method stub
			return cnt - o.cnt;
		}
		
		
		
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st= new StringTokenizer(br.readLine());
		
		m = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		
		arr = new int [n][m];
		visited = new boolean[n][m];
		
		for(int i = 0 ; i < n; i++) {
			String tmp[] = br.readLine().split("");
			for(int j = 0 ; j < tmp.length; j++) {
				arr[i][j] = Integer.parseInt(tmp[j]);
			}
		}
		
		
		System.out.println(bfs());
		
		
	}
	
	public static int bfs() {
		PriorityQueue<point> que = new PriorityQueue<point>();
	
		que.add(new point(0, 0, 0));
		visited[0][0] = true;
		
		while(!que.isEmpty()) {
			
			point p =  que.poll();
			int r = p.r;
			int c = p.c;
			
			for(int i = 0 ; i < 4; i++) {
				int mr = r+a[i];
				int mc = c+b[i];
				
				if(mr == n-1 && mc == m-1) {
					return p.cnt;
				}
				
				
				if(mr >=0&& mc >=0 && mr < n && mc <m) {
					if(!visited[mr][mc]) {
						visited[mr][mc] = true;
						que.add(new point(mr, mc, arr[mr][mc] == 0 ? p.cnt : p.cnt+1));
					}
				}
				
			}
			
		}
		return 0;
		
		
		
	}
	
	
	
}
