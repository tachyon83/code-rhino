
import java.io.*;
import java.util.*;

public class Main {
	static int n, m, v;
	static int[][] map;
	static boolean visit[];
	static int count = 0;
	static Stack<Integer> stack = new Stack<>();

	static void dfs(int jump) {
		stack.add(jump);
		visit[jump] = true;
		count++;
		//System.out.println("count = " + count+"\n");

		
		while (!stack.empty()) {
			int noPush = 1;
			int a = stack.peek();
			visit[a] = true;
			//System.out.println("a = " + a);

			
			for (int i = 1; i <= n; i++) {

				if (!visit[i] && map[a][i] == 1) {
					stack.add(i);
					//System.out.println("\nstack에 " + i + " add");
					visit[i] = true;
					noPush = 0;
					break;

				}
		
			}
			if(noPush == 1 && !stack.empty()) {
				stack.pop();
				//System.out.println("pop "+ stack.pop());
				
			}
			
		}

	}

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		String[] s = bf.readLine().split(" ");
		n = Integer.parseInt(s[0]); // 정점의 개수
		m = Integer.parseInt(s[1]); // 간선의 개수

		map = new int[n + 1][n + 1];

		visit = new boolean[n + 1];

		for (int i = 0; i < m; i++) {
			String[] s2 = bf.readLine().split(" ");
			int a = Integer.parseInt(s2[0]);
			int b = Integer.parseInt(s2[1]);

			map[a][b] = map[b][a] = 1;
		}

	
		

		for (int i = 1; i <= n; i++) {
			if (visit[i] == false) {
				dfs(i);
				visit[i] = true;
				//System.out.println("dfs(" + i + ")로 ㄱㄱ");
			}
		}

		System.out.println(count);

	}

}


