public class 섬의개수_4963 {

    private static int n;
    private static int m;
    private static int[][] map;
    private static boolean[][] visited;
    private static int[] dy = {-1,-1,0,1,1,1,0,-1}; //상 우상 우 우하 하 좌하 좌 좌상
    private static int[] dx = {0,1,1,1,0,-1,-1,-1};
    private static void dfs(int y, int x) {

        for(int i = 0; i < 8; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if(next_x < 0 || next_y < 0 || next_y >= n || next_x >= m) continue;
            if(map[next_y][next_x] == 0 || visited[next_y][next_x]) continue;
            visited[next_y][next_x] = true;
            dfs(next_y, next_x);
        }
    }


    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        while(true) {
            st = new StringTokenizer(input.readLine());
            m = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());
            if( n == 0 && m == 0) break;
            map = new int[n][m];
            visited = new boolean[n][m];
            for(int i = 0; i < n; i++){
                st = new StringTokenizer(input.readLine());
                for(int j = 0; j < m; j++){
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            int cnt = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(map[i][j] == 0 || visited[i][j]) continue;
                    visited[i][j] = true;
                    dfs(i,j);
                    cnt++;
                }
            }
            sb.append(cnt).append("\n");
        }
        System.out.println(sb);

    }
}
