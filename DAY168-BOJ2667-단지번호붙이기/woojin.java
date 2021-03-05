import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main{
    static int[][] map = new int[26][26];
    static int count = 0;
    static int n = 0;
    static int[][] check = {{-1,0},{1,0},{0,-1},{0,1}};
    static int[] house;
    static boolean[][] visit;

    // ac = apartment complex
    static void dfs(int x, int y){
        map[x][y] = count;
        visit[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int dx = x + check[i][0];
            int dy = y + check[i][1];
            if(0>dx || 0>dy || dx>=n || dy>=n)
                continue;
            else{
                if(!visit[dx][dy] && map[dx][dy] == 1)
                    dfs(dx,dy);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        visit = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            String[] Input = br.readLine().split("");
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(Input[j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(!visit[i][j] && map[i][j]==1){
                    count++;
                    dfs(i,j);
                }
            }
        }

        house = new int[count+1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(map[i][j] != 0)
                    house[map[i][j]]++;
            }
        }

        Arrays.sort(house);

        System.out.println(count);
        for (int i = 1; i < house.length; i++) {
            System.out.println(house[i]);
        }
    }
}
