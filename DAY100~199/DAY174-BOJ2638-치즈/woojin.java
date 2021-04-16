// 자꾸 틀렸다고 합니다. 접촉 공기를 다른 숫자로 바꾸어서 내부 공간을 파악하고 계산했는데 무엇이 틀렸는 지 모르겠습니다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BJ_2638 {
    
    static int[][] map;
    static boolean[][] visit;
    static int[][] check = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }};
    static int n, m, count = 0;
    static boolean flag = false;
    
    static void checkOuterSpace (int x, int y) {
        visit[x][y] = true;
        map[x][y] = 2;
    
        for (int i = 0; i < 4; i++) {
            int dx = x + check[i][0];
            int dy = y + check[i][1];
        
            if (0 <= dx && dx < n && 0 <= dy && dy < m) {
                if (!visit[dx][dy] && map[dx][dy] == 0) {
                    checkOuterSpace(dx, dy);
                }
            }
        }
    }
    
    static boolean checkCCondition (int x, int y) {
        if (( map[x - 1][y] == 2 && map[x][y + 1] == 2 ) || ( map[x + 1][y] == 2 && map[x][y + 1] == 2 ) || ( map[x][y - 1] == 2 && map[x - 1][y] == 2 ) || ( map[x + 1][y] == 2 && map[x][y - 1] == 2 ) || ( map[x - 1][y] == 2 && map[x + 1][y] == 2 ) || ( map[x][y - 1] == 2 && map[x][y + 1] == 2 )) {
            return true;
        }
        return false;
    }
    
    static void dfs (int x, int y) {
        visit[x][y] = true;
        
        if (checkCCondition(x, y)) {
            map[x][y] = 3;
        }
        
        for (int i = 0; i < 4; i++) {
            int dx = x + check[i][0];
            int dy = y + check[i][1];
            
            if (0 <= dx && dx < n && 0 <= dy && dy < m) {
                if (!visit[dx][dy] && map[dx][dy] == 1) {
                    dfs(dx, dy);
                }
            }
        }
    }
    
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] mapInfo = br.readLine().split(" ");
        n = Integer.parseInt(mapInfo[0]);
        m = Integer.parseInt(mapInfo[1]);
        
        map = new int[n + 1][m + 1];
        visit = new boolean[n + 1][m + 1];
        
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(input[j]);
            }
        }
        
        checkOuterSpace(0,0);
    
        for (int i = 0; i < visit.length; i++) {
            Arrays.fill(visit[i], false);
        }
        
        while (true) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (map[i][j] == 1) {
                        flag = true;
                        dfs(i, j);
                    }
                }
            }
            
            if (!flag) {
                System.out.println(count);
                break;
            }
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (map[i][j] == 3) {
                        map[i][j] = 2;
                    }
                }
            }
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if(map[i][j] == 0){
                        checkOuterSpace(i,j);
                    }
                }
            }
            
            for (int i = 0; i < visit.length; i++) {
                Arrays.fill(visit[i], false);
            }
            
            count++;
            flag = false;
        }
        
    }
    
}
