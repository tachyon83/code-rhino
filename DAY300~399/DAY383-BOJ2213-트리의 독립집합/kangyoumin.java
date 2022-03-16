import java.io.*;
import java.util.*;

public class Main {

	static List<Integer>[] node_list;
	static int[] weight;
	static int[][] memo;
	static boolean[] check;
	static List<Integer> res;	

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		weight = new int[n+1];
		node_list = new ArrayList[n+1];
		memo = new int[n+1][2];
		check = new boolean[n+1];
		res = new ArrayList<>();
		for(int i=0; i<n+1; i++) {
			node_list[i] = new ArrayList<>();
		}
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for(int i=1; i<n+1; i++) {
			weight[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i=0; i<n-1; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
		
			node_list[b].add(a);
			node_list[a].add(b);
		}
		
		traversal(1);
		
		if(memo[1][1]> memo[1][0] ) {
			System.out.println(memo[1][1]);
			trace(1,1);
		}else {
			System.out.println(memo[1][0]);
			trace(1,0);
		}
		
		Collections.sort(res);
		for(int num : res ) {
			System.out.print(num+" ");
		}
	}
	
	static void traversal(int pos) {

		int child_num = node_list[pos].size();
		
		memo[pos][0] = 0;
		memo[pos][1] = weight[pos]; 
		
		if(child_num ==0) return;
		
		check[pos] = true;
		
		for(int child : node_list[pos]) {
			if(!check[child]) {
				traversal(child);
				
				if(memo[child][0] > memo[child][1]) {
					memo[pos][0] += memo[child][0];  
					
				}else { 
					memo[pos][0] += memo[child][1]; 
				}
				
				memo[pos][1] += memo[child][0]; 
			}
		}
		check[pos] = false;
	}
	
	static void trace(int pos, int attend) {
		check[pos] = true;
		if(attend==1) {
			res.add(pos);
			for(int i=0; i<node_list[pos].size(); i++) {
				int next = node_list[pos].get(i);
				if(!check[next]) {
					trace(next, 0);
				}
			}
		}
		else {
			for(int i=0; i<node_list[pos].size(); i++) {
				int next = node_list[pos].get(i);
				if(!check[next]) {
					if(memo[next][1] > memo[next][0]) {
						trace(next, 1);
					}else {
						trace(next, 0);
					}
				}
			}
		}
		check[pos] = false;
		
	}
}
