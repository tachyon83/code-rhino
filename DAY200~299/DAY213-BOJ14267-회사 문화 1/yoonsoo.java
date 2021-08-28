

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

	static int ans[];
	static int n;
	static ArrayList<Integer> list[];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		String tmp[] = br.readLine().split(" ");
		
		
		ans = new int[n+1];
		list = new ArrayList[n+1];
		
		for(int i = 1 ; i <=n;i++) {
			list[i] = new ArrayList<Integer>();
		}
		
		for(int i = 2 ; i <=n;i++) {
		
			list[Integer.parseInt(tmp[i-1])].add(i);
		}
		
		
		for(int i = 0 ; i < m ;i++) {
			st = new StringTokenizer(br.readLine());
			int num = Integer.parseInt(st.nextToken());
			int cnt = Integer.parseInt(st.nextToken());
			ans[num] += cnt;
		}
		
	
		dfs(1,0);
		
		
		for(int i = 1 ; i < ans.length;i++) {
			System.out.print(ans[i]+" ");
		}
		
		
	}
	
	public static void dfs(int master,int cnt) {
		
		
		for(int i = 0 ; i <list[master].size();i++) {
			ans[list[master].get(i)]+=cnt;
			dfs(list[master].get(i),ans[list[master].get(i)]);
		
		}
		
	}
	
	
}
