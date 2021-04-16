import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int map[];
	static boolean visited[];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		map = new int[101];
		visited = new boolean[101];
		for(int i = 1 ; i <=100 ;i++) {
			map[i] = i;
		}
		
		
		for(int i = 0 ; i < n+m; i++) {
			st = new StringTokenizer(br.readLine());

			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			map[a] = b;
		}

		bfs();
	}
	public static void bfs() {
		Queue<int[]> que= new LinkedList<int[]>();
		que.add(new int[] {1,0});
	
		while(!que.isEmpty()) {
			int now[] = que.poll();
			int time = now[1];
			int cur = now[0];
			
			if(cur == 100) {
				System.out.println(time);
				return;
			}
			for(int i = 1 ; i <= 6;i++) {
				if(cur+i <=100 && !visited[cur+i]) {
					visited[cur+i] = true;
					que.add(new int[] {map[cur+i],time+1});
				}
			}
			
			
			
		}
		
		
		
	}
	
	
	
	
}
