import java.util.*;

class Pair{
    Integer x;
    Integer y;
    public Pair(Integer x, Integer y){
        this.x = x;
        this.y = y;
    }
    public Integer first(){
        return x;
    }
    public Integer second(){
        return y;
    }
}
 
class Solution {
    int[] dx = {0, 0, -1, 1};
    int[] dy = {-1, 1, 0, 0};
    boolean[][] visited;
    
    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        visited = new boolean[m][n];
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(picture[i][j] != 0 && !visited[i][j]) {
                    maxSizeOfOneArea = Math.max(maxSizeOfOneArea, bfs(m, n, i, j, picture));
                    numberOfArea++;
                }
            }
        }
        
        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
    
    int bfs(int m, int n, int x, int y, int[][] picture){
        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(x, y));
        visited[x][y] = true;
        int range = 1;
        int target = picture[x][y];
        
        while(!queue.isEmpty()){
            Pair pair = queue.poll();
            
            for(int i = 0; i < 4; i++){
                int nx = pair.x + dx[i];
                int ny = pair.y + dy[i];
                
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }
                
                if(picture[nx][ny] == target && !visited[nx][ny]) {
                    queue.add(new Pair(nx, ny));
                    visited[nx][ny] = true;
                    range++;
                }
            }
        }
        
        return range;
    }
}
