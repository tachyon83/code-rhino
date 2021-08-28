public class 내리막길_1520 {

    private static int n,m;
    private static int[] dx = {0, 0, -1, 1}; //상하좌우
    private static int[] dy = {-1, 1, 0, 0};
    private static int map[][];
    private static int dp[][];
    private static int result = 0;


    private static int dfs(int y, int x) {

        if(y == n - 1 && x == m - 1) return 1;
        //아직 방문되지 않았다면
        if(dp[y][x] == -1) {
            dp[y][x] = 0;
            for (int i = 0; i < 4; i++) {
                int next_y = y + dy[i];
                int next_x = x + dx[i];
                if (next_x < 0 || next_y < 0 || next_x >= m || next_y >= n) continue;
                if (map[next_y][next_x] >= map[y][x]) continue;
                dp[y][x] += dfs(next_y, next_x);
            }
        }
        return dp[y][x];
    }

    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(input.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n][m];
        dp = new int[n][m]; //0은 몇번을 걸쳐왔는지, 1은 현재까지 동일한 거리가 몇개인지 카운트
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(input.readLine());
            for(int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                dp[i][j] = -1;
            }
        }
        System.out.println(dfs(0,0));
    }
}
