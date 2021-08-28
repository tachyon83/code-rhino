

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int N, K, max = 987654321, answer = max;
	static int dp[][];

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		dp = new int[N][N];
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < N; j++) {
				dp[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
//		플로이드 와샬
//		중간 지점
		for(int i = 0; i < N; i++) {
//			출발지점
			for(int j = 0; j < N; j++) {
				if(i == j) continue;
//				도착지점
				for(int k = 0; k < N; k++) {
					if(k == j || k == i) continue;
					dp[j][k] = Math.min(dp[j][k], dp[j][i] + dp[i][k]);
				}
			}
		}
		
		Dfs((1<<K), 0, 1, K);

		System.out.println(answer);

	}
	
	static void Dfs (int visit, int dist, int cnt, int current) {
//		모든 행성을 돌았을 때
		if(cnt == N) {
			answer = Math.min(answer, dist);
			return;
		}
		
//		모든 행성을 돌지 않았는 데도 거리가 answer보다 클때..그냥 return
		if(answer <= dist) return;
		
		for(int i = 0; i < N; i++) {
//			방문한적 있다면
			if((visit & (1<<i)) != 0) continue;
//			방문한 것에 추가, 거리는 current -> i로 이동으로 , ..
			Dfs(visit | (1<<i), dist + dp[current][i], cnt+1, i);
		}
	}

}
