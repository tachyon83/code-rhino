import java.util.*;

class Solution {
    static int max = 200*100000 + 1;
    public int solution(int n, int s, int a, int b, int[][] fares) {
        int dp[][] = new int[n+1][n+1];
        
//        최소값을 구할 것이기 때문에 max로 초기화 
//        -> 만약 연결이 안되어있는 경우 cost가 최대 금액이 됨
        for(int i = 0; i < n+1; i++) {
        	Arrays.fill(dp[i], max);
        	dp[i][i] = 0;
        }
        
        for(int i = 0; i < fares.length; i++) {
        	int start = fares[i][0];
        	int end = fares[i][1];
        	int cost = fares[i][2];
        	
//        	방향에 따라 금액이 같다
        	dp[start][end] = cost;
        	dp[end][start] = cost;
        }
        
//        제일 바깥쪽 반복문은 거쳐가는 꼭짓점이고, 두 번째 반복문은 출발하는 꼭짓점, 세 번째 반복문은 도착하는 꼭짓점이다.
//        1이상 n이하
        for(int i = 1; i < n+1; i++) {
        	for(int j = 1; j < n+1; j++) {
        		for(int k = 1; k < n+1; k++) {
        			dp[j][k] = Math.min(dp[j][k], dp[j][i] + dp[i][k]);
        		}
        	}
        }

//        합승안 하는 경우가 더 쌀 때 answer이 return됨.
        int answer = dp[s][a] + dp[s][b];
        
//        합승하는 경우와 안하는 경우 비교
        for(int i = 1; i < n+1; i++) {
        	answer = Math.min(answer, dp[s][i] + dp[i][a] + dp[i][b]);
        }
        return answer;
    }
}
