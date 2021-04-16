import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	
	
	static int s;
	static boolean visited[][];
	public static void main(String[] args) throws  IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		s = Integer.parseInt(br.readLine());
		visited = new boolean[1001][1001];
		visited[1][0] =true;
		bfs(s);

	}
	
	public static void bfs(int end) {
		Queue<int[]> que = new LinkedList<int[]>();
		que.add(new int[] {1,0,0});

		while(!que.isEmpty()) {
			int now[] = que.poll();
			int cnt = now[0];
			int time = now[1];
			int board = now[2];
			if(cnt == end) {
				System.out.println(time);
				return;
			}
			
			if(!visited[cnt][cnt]) {
				//복 
				visited[cnt][cnt] = true;
				que.add(new int[] {cnt,time+1,cnt});
			}
				
			if(cnt+board <=1000 && !visited[cnt+board][board]) {
				//붙
				visited[cnt+board][board] = true;
				que.add(new int[] {cnt+board,time+1,board});
			}
			
			if(cnt-1 >=0&&!visited[cnt-1][board]) {
				//삭제
				visited[cnt-1][board] = true;
				que.add(new int[]{cnt-1,time+1,board});
				
			}
			
			
		}
		
	}
	
}
