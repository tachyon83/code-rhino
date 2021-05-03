
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Review {
	
	static int num[];
	static ArrayList<Integer> list[];
	static int time[];
	static int dp[];

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		int n = Integer.parseInt(br.readLine());
		time = new int[n+1];
		num = new int[n+1];
		list = new ArrayList[n+1];
		dp = new int[n+1];
		
		for(int i = 1 ; i <=n;i++) {
			list[i] = new ArrayList<Integer>();
		}

		for(int i = 1 ; i <= n ;i++ ) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			time[i] = a;
			
			int amt = Integer.parseInt(st.nextToken());
			num[i] = amt;
			
			for(int j = 0 ; j < amt ; j++) {
				list[Integer.parseInt(st.nextToken())].add(i);
			}
		}
		
		topology(n);
		Arrays.sort(dp);
		System.out.println(dp[n]);
		System.out.println(Arrays.toString(num));
		
	}
	
	public static void topology(int n) {
		Queue<Integer> que = new LinkedList<Integer>();
		
		for(int i = 1 ; i < list.length;i++) {
			dp[i] = time[i];
			if( num[i] == 0) {
				que.add(i);				
			}
			 
		}
		
		
		for(int i = 1 ; i <= n;  i++) {
			if(que.isEmpty()) {
				return; 
			}
			int x = que.poll();
		
		
			for(int j =0 ; j < list[x].size();j++) {
				int get = list[x].get(j);
				
	
				if(dp[get] < dp[x]+time[get] ) {
					num[get]--;
					dp[get] = dp[x]+time[get];
				}
				
				
				if(num[get] == 0) {
					que.add(get);
				}
							
			}
			
			
			
		}
		
		
		
		
		
	}
	
	
	
}
