package platinum5.B15669;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M;
	static ArrayList<Integer>[] al;
	
	static class Node {
		int color;
		int num;

		public Node(int color, int num) {
			this.color = color;
			this.num = num;
		}
		
	}
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine()," ");
		N = Integer.parseInt(str.nextToken());
		M = Integer.parseInt(str.nextToken());
		
		al = new ArrayList[N+1];
		for(int i=0;i<=N;i++) {
			al[i] = new ArrayList<>();
		}
		
		int u,v,c;
		for(int i=0;i<N;i++) {
			str = new StringTokenizer(br.readLine()," ");
			u = Integer.parseInt(str.nextToken());
			v = Integer.parseInt(str.nextToken());
			al[u].add(v);
		}
		
		for(int i=0;i<M;i++) {
			str = new StringTokenizer(br.readLine()," ");
			
			
		}
	}

}
