// 2573번 빙산 (gold 4)

// 제출 결과: [메모리: 237212KB 시간: 920ms]
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Stack;

public class BJ_2573 {
    static class Node {
        int x;
        int y;
        int height;
        
        Node(int x, int y){
            this.x = x;
            this.y = y;
            this.height = 0;
        }
        
        Node(int x, int y, int height){
            this.x = x;
            this.y = y;
            this.height = height;
        }
    }
    
    static int[][] map;
    static boolean[][] visit;
    static int[][] check = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    static int n, m;
    static int result = 0;
    
    public static void bfs(int x, int y){
        Stack<Node> heightInfo = new Stack<>();
        ArrayList<Node> icebergList = new ArrayList<>();
    
        heightInfo.add(new Node(x, y));
        
        while(!heightInfo.isEmpty()){
            Node temp = heightInfo.pop();
            int count = 0;
            
            visit[temp.x][temp.y] = true;
    
            for (int i = 0; i < 4; i++) {
                int dx = temp.x + check[i][0];
                int dy = temp.y + check[i][1];
                if(0 <= dx && dx < n && 0 <= dy && dy < m){
                    if(map[dx][dy] != 0){
                        if(!visit[dx][dy])
                            heightInfo.add(new Node(dx,dy));
                    } else
                        count++;
                }
            }
            
            int height = map[temp.x][temp.y] - count > 0 ? map[temp.x][temp.y] - count : 0;
            icebergList.add(new Node(x, y, height));
        }
    
        for (Node n : icebergList) {
            map[n.x][n.y] = n.height;
        }
        
    }
    
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] mapInfo = br.readLine().split(" ");
        n = Integer.parseInt(mapInfo[0]);
        m = Integer.parseInt(mapInfo[1]);
        
        map = new int[n][m];
    
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(input[j]);
            }
        }
        
        int iceberg;
        while(true){
            iceberg = 0;
            visit = new boolean[n][m];
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if(!visit[i][j] && map[i][j] != 0){
                        bfs(i,j);
                        iceberg++;
                    }
                }
            }
            
            if(iceberg == 0) {
                System.out.println(0);
                break;
            }
    
            if (iceberg >= 2) {
                System.out.println(result);
                break;
            }
            
            result++;
        }
    }
}
