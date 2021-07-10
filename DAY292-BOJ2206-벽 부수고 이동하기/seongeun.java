
public class 벽부수고이동하기_2206 {

    private static int[][] map;
    private static boolean[][][] visited;
    private static int[] dx = {0,0,-1,1}; //상,하,좌,우
    private static int[] dy = {-1,1,0,0};

    private static int bfs(int n, int m) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0,0,1,0});
        visited[0][0][0] = true;

        int min = Integer.MAX_VALUE;
        while(!q.isEmpty()) {
            int[] location = q.poll();
            int y = location[0];
            int x = location[1];
            int cnt = location[2];
            int check = location[3];

            if(y == n - 1 && x == m - 1) {
                min = cnt;
                break;
            }
            for(int i = 0; i < 4; i++) {
                int next_y = y + dy[i];
                int next_x = x + dx[i];
                if (next_y >= 0 && next_x >= 0 && next_y < n && next_x < m) {
                    if (map[next_y][next_x] == 0) {
                        if (!visited[next_y][next_x][0]) {
                            visited[next_y][next_x][0] = true;
                            q.add(new int[]{next_y, next_x, cnt + 1, check});
                        }
                    }
                    if (map[next_y][next_x] == 1) {
                        if (check == 1) continue;
                        if (!visited[next_y][next_x][1]) {
                            visited[next_y][next_x][1] = true;
                            q.add(new int[]{next_y, next_x, cnt + 1, check + 1});
                        }
                    }
                }
            }
        }
        return min == Integer.MAX_VALUE ? -1 : min ;
    }

    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(input.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());


        map = new int[n][m];
        visited = new boolean[n][m][2];
        for(int i = 0; i < n; i++){
            String str = input.readLine();
            for(int j = 0; j < m; j++) {
                map[i][j] = str.charAt(j) - '0';
            }
        }

        System.out.println(bfs(n,m));

    }
}
