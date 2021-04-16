// 1303번 전투(silver 1)

// 제출 결과 [메모리: 17324KB 시간: 208ms]
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ_1303 {
    static String[][] map;
    static boolean[][] visit;
    static int[][] check = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    static int n, m;
    static int wStrength = 0, bStrength = 0;
    static int count=0;

    public static void w_dfs(int y, int x){
        visit[y][x] = true;
        wStrength += (count+1) * (count+1) - count * count;

        for (int i = 0; i < 4; i++) {
            int dx = x + check[i][0];
            int dy = y + check[i][1];

            if(0 <= dx && dx < n && 0 <= dy && dy < m){
                if(!visit[dy][dx] && map[dy][dx].equals("W")){
                    count++;
                    w_dfs(dy,dx);
                }
            }
        }
    }

    public static void b_dfs(int y, int x){
        visit[y][x] = true;
        bStrength += (count+1) * (count+1) - count * count;

        for (int i = 0; i < 4; i++) {
            int dx = x + check[i][0];
            int dy = y + check[i][1];

            if(0 <= dx && dx < n && 0 <= dy && dy < m){
                if(!visit[dy][dx] && map[dy][dx].equals("B")){
                    count++;
                    b_dfs(dy,dx);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);
        map = new String[m][n];
        visit = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            input = br.readLine().split("");
            for (int j = 0; j < n; j++) {
                map[i][j] = input[j];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(!visit[i][j] && map[i][j].equals("W")) {
                    count = 0;
                    w_dfs(i,j);
                }
                if(!visit[i][j] && map[i][j].equals("B")) {
                    count = 0;
                    b_dfs(i,j);
                }
            }
        }

        System.out.println(wStrength + " " + bStrength);
    }
}
