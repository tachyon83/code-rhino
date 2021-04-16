
class Solution {
	
	static boolean [] visit;
	static int map[][];
	static int n;
	
	void dfs(int x) {
		//System.out.println("dfs 내부 "+x+" visit check");
		visit[x] = true;
		
		for(int i=0;i<n;i++) {
			if(map[x][i] == 1 && !visit[i]) {
				dfs(i);
			}
		}
		
	}
	
    public int findCircleNum(int[][] isConnected) {
    	n = isConnected.length; //3
    	visit = new boolean[n];
    	
    	map = isConnected;
    	
    	int count = 0;
    	for(int i=0;i<n;i++) {
    			if(!visit[i]) {
    				//System.out.println(i+"일 때, dfs로 이동");
    				dfs(i);
    				count++;

    				//System.out.println(i+"일 때, count = "+count);
    			}
    		}
    	
    	
        return count;
    }
}
