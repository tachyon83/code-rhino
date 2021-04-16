// 1926번 그림(silver 1)

// 제출 결과 [메모리: 58460KB 시간: 392ms]
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ_1926 {
    private static int[][] map;
    private static boolean[][] visit;
    private static int n,m;
    private static int[][] check = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    private static int count = 0;
    private static int checkArea;
    private static int maxArea = 0;

    private static void dfs(int x, int y) {
        visit[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int dx = x + check[i][0];
            int dy = y + check[i][1];

            if(0 <= dx && 0 <= dy && dx < n && dy < m){
                if(!visit[dx][dy] && map[dx][dy] == 1){
                    checkArea++;
                    dfs(dx, dy);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] mapInput = br.readLine().split(" ");
        n = Integer.parseInt(mapInput[0]);
        m = Integer.parseInt(mapInput[1]);

        map = new int[n+1][m+1];
        visit = new boolean[n+1][m+1];

        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(input[j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(!visit[i][j] && map[i][j] == 1) {
                    count++;
                    checkArea = 1;
                    dfs(i, j);
                    if(checkArea > maxArea)
                        maxArea = checkArea;
                }
            }
        }

        System.out.println(count);
        System.out.println(maxArea);
    }

}
