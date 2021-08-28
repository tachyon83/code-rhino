import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static class Node{
	
		int b;
		int weight;
		
		public Node(int b, int weight) {
			super();
		
			this.b = b;
			this.weight = weight;
		}
		
		
		
	}
	
	
	static ArrayList<Node> list[];
	static boolean visited[];
	static int max;
	static int length[];
	static int idx= 0;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		if ( n == 1) {
			System.out.println(0);
		}else {
			
			length = new int[n+1];
	
			visited = new boolean[n+1];
			list = new ArrayList[n+1];
			for(int i = 1 ; i<=n;i++) {
				list[i] = new ArrayList<Node>();
			}
			
			
			
			for(int i = 0 ; i < n-1;i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				int weight = Integer.parseInt(st.nextToken());
				
				list[a].add(new Node(b, weight));
				list[b].add(new Node(a, weight));
				
			}
			
	
			visited[1] = true;
			dfs(1,0);
			
			Arrays.fill(length, 0);
			visited = new boolean[n+1];
			max = 0;
			visited[idx] = true;
			
			dfs(idx,0);
	
			System.out.println(max);
	
		}
		
		
	}
	
	public static int dfs(int start,int weight) {
		

		for(int i = 0 ;i < list[start].size();i++) {
			Node next = list[start].get(i);
			if(!visited[next.b]) {
				visited[next.b] = true;
				dfs(next.b,weight+next.weight);
				
			}

		}
		
		
		if(max < weight) {
			max = weight;
			idx = start;
		}
		
		length[start] = weight;
	
	

		return  length[start];
		
	}
	
	
}
