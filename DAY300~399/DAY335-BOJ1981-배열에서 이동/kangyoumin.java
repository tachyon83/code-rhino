import java.io.*;
import java.util.*;

public class Main {
	
	static class Node {
		int r, c;
		
		Node(int r, int c){
			this.r = r;
			this.c = c;
		}
	}
	
	static ArrayList<Integer> numbers;
	static int[][] map;
	static int N;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		N = Integer.parseInt(br.readLine());
		
		numbers = new ArrayList<>();
		map = new int[N][N];
		
		for(int r = 0 ; r < N ; ++r) {
			st = new StringTokenizer(br.readLine());
			for(int c = 0 ; c < N ; ++c) {
				map[r][c] = stoi(st.nextToken());
				if(!numbers.contains(map[r][c])) {
					numbers.add(map[r][c]);
				}
			}
		}
		Collections.sort(numbers);
		
		solve();
	}
	
	private static void solve() {
		int min = 0, max = 0;
		int ans = Integer.MAX_VALUE;
		
		while(min < numbers.size() && max < numbers.size()) {
			if(bfs(numbers.get(min), numbers.get(max))) {
				int gap = numbers.get(max) - numbers.get(min);
				ans = ans > gap ? gap : ans;
				min++;
			} else {
				max++;
			}
		}
		
		System.out.println(ans);
	}

	private static boolean bfs(int min, int max) {
		if(map[0][0] < min || map[0][0] > max) return false;
		
		int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		boolean[][] visited = new boolean[N][N];
		Queue<Node> q = new LinkedList<>();
		
		q.offer(new Node(0, 0));
		visited[0][0] = true;
		
		while(!q.isEmpty()) {
			Node now = q.poll();
			
			if(now.r == N - 1 && now.c == N - 1) {
				return true;
			}
			
			for(int d = 0 ; d < 4 ; ++d) {
				int nr = now.r + dir[d][0];
				int nc = now.c + dir[d][1];
				
				if(nr >= N || nr < 0 || nc >= N || nc < 0 || visited[nr][nc]) continue;
				
				if(map[nr][nc] >= min && map[nr][nc] <= max) {
					visited[nr][nc] = true;
					q.offer(new Node(nr, nc));
				}
			}
		}
		return false;
	}
