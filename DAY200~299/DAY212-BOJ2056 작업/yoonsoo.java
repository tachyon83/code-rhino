
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {

	static int num[];
	static int time[];
	static ArrayList<Integer> list[];
	static int n;
	static int sum = 0;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		num = new int[n+1];
		time = new int[n+1];
		
		list = new ArrayList[n+1];
		
		for(int i = 1 ; i<=n;i++) {
			list[i] = new ArrayList<Integer>();
		}
		
		for(int i = 1 ; i <= n;i++ ) {
			String tmp[] = br.readLine().split(" ");
			for(int j = 0 ; j < tmp.length;j++) {
				if(j == 0) {
					//걸리는 시간
					time[i] = Integer.parseInt(tmp[j]);
				}else if(j == 1) {
					//작업들 개수
					num[i] = Integer.parseInt(tmp[j]);
				}else {
					//작업들 번호
					list[Integer.parseInt(tmp[j])].add(i);
				}
				
			}
		}
		topology();
	

	}
	public static void topology() {
		Queue<Integer> que = new LinkedList<Integer>();
		int dp[] = new int[n+1];
	
		for(int i = 1 ; i <=n;i++) {
			
			que.add(i);
			dp[i] = time[i];
		}
		
		
		for(int i = 1 ; i<=n; i++) {
			if(que.isEmpty())return;
			
			int cur = que.poll();

			for(int j = 0 ; j < list[cur].size();j++) {
				int get = list[cur].get(j);
				
				if(dp[get] < time[get] + dp[cur]) {
					dp[get] = time[get]+dp[cur];
				
				}
				
			
				
				if(num[get] == 0) {
					que.add(get);
				}
				
			}

			
		}

		Arrays.sort(dp);
		System.out.println(dp[n]);
		
	}
	
	
	
}
