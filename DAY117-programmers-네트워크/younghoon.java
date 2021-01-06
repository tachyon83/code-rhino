class Solution {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        boolean networks[] = new boolean[n];
        for(int i = 0; i < n; i++){
            networks[i] = false;
        }
        for (int i = 0; i < n; i++) {
            if (!networks[i]) {
                dfs(computers, i, networks);
                answer++;
            }
        }
        return answer;
    }
    
    public void dfs(int[][] computers, int i, boolean[] networks) {
        networks[i] = true;
        for (int j = 0; j < computers.length; j++) {
           if (i != j && computers[i][j] == 1 && networks[j] == false) {
                dfs(computers, j, networks);
           }
        }
     }
}
