class Solution {
    static boolean[] visit; 
	public int solution(int n, int[][] computers) {
        int answer = 0;
        visit = new boolean[n]; 
        for (int i = 0; i < n; i++) {
//          방문안된 \]]\\] 노드들만
        	if(!visit[i]) {
//        		이어지는 노드들을 visit=true로 바꿈
        		dfs(i, computers, n);
//        		네트워크 하나 생성
        		answer++;
        	}
        }
        return answer;
    }
	static void dfs(int node, int[][] arr, int n) {
		visit[node] = true;
		for(int i = 0; i < n; i++) {
			if(visit[i] == false && arr[node][i] == 1) {
				dfs(i, arr, n);
			}
		}
	}
}
