import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	static ArrayList<Integer>[] list;
	static boolean visited[];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		
		int num = sc.nextInt(); // 숫자
		int line = sc.nextInt(); // 간선의 개수
		int ans = 0;
		
		visited = new boolean[num+1];
		list = new ArrayList[num+1];
		
		for(int i = 1 ; i <= num;i++) {
			list[i] = new ArrayList<Integer>();
		}
		
		
		
		for(int i = 1 ; i <= line;i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			
			list[a].add(b);
			list[b].add(a);
		}
		
		for(int i = 1; i <=num;i++) {
		
			if(visited[i] != true) {
				dfs(i);
				ans++;
			}
			
		}
		System.out.println(ans);

	}
	
	public static void dfs(int d) {
		if(visited[d] == true) return;
		else {
			visited[d] = true;
			
			
			for(int i : list[d]) {
				dfs(i);
			}
			
		}
		
	}
	
}
