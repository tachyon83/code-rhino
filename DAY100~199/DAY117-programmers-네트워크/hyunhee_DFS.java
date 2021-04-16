import java.util.*;
class Solution {
    static boolean[] check;
	
	public int solution(int n, int[][] computers) {
		check = new boolean[computers.length];
		int answer=0;
		for(int i=0;i<computers.length;i++) {
			if(!check[i]) {
				check[i] = true;
				dfs(i, computers);
				answer++;
			}
		}
		
		
		return answer;
	}

	private void dfs(int start, int[][] computers) {
		for(int end=0;end<computers.length;end++) {
			if(computers[start][end]==1 && !check[end]) {
				check[end] = true;
				dfs(end, computers);
			}
		}
	}
}