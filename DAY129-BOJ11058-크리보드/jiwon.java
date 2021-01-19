//푸는 중 규칙 파악 실패..


import java.io.*;
import java.util.*;



public class Main{
	static int dp[];
	static int N; 



	public static void main(String [] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(bf.readLine());
		dp = new int[101];
		for(int i=0;i<=6;i++) {
			dp[i] = i;
 		}
		
		for(int i=7,j=2; i<=N;i++,j++) {
				if(j%3==0) {
					System.out.print("i="+i+", j="+j);
					dp[i] = dp[i-2] + dp[i-3] + 1;
					System.out.println("    dp[i]="+dp[i]);
				}else {
					System.out.print("i="+i+", j="+j);
					dp[i] = dp[i-2] + dp[i-3];
					System.out.println("    dp[i]="+dp[i]);
				}
			
		}
			
		
		for(int i=1;i<N;i++) {
			
			System.out.println(i+" "+dp[i]);
		}
		
		System.out.println(dp[N]);

	}




}

