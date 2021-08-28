public class Main {

    private static int n;
    private static int[][] map;
    private static int[][] visited;
    private static int[] dy = {-1,0,1,0};
    private static int[] dx = {0,1,0,-1};
    private static void dfs(int y, int x, int cnt) {

        for(int i = 0; i < 4; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if(next_x < 0 || next_y < 0 || next_y >= n || next_x >= n) continue;
            if(map[next_y][next_x] == 0 || visited[next_y][next_x] != 0) continue;
            visited[next_y][next_x] = cnt;
            dfs(next_y, next_x, cnt);
        }
    }
    private static int getBridgeDistance(boolean[][] visit, int num, int start_y, int start_x) {

        int minDistance = Integer.MAX_VALUE;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{start_y,start_x,0});
        visit[start_y][start_x] = true;

        while(!q.isEmpty()){
            int[] location = q.poll();
            int y = location[0];
            int x = location[1];
            int cnt = location[2];

            if(visited[y][x] != 0 && visited[y][x] != num) {
                minDistance = Math.min(minDistance,cnt);
                break;
            }
            for(int i = 0; i < 4; i++){
                int next_y = y + dy[i];
                int next_x = x + dx[i];
                if(next_y < 0 || next_x < 0 || next_y >= n || next_x >= n) continue;
                if(visited[next_y][next_x] == num || visit[next_y][next_x]) continue;
                visit[next_y][next_x] = true;
                q.add(new int[]{next_y, next_x, cnt + 1});
            }
        }

        return minDistance - 1;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(input.readLine());
        map = new int[n][n];
        visited = new int[n][n];
        for(int i = 0; i < n; i++){
            StringTokenizer st = new StringTokenizer(input.readLine());
            for(int j = 0; j < n; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int cnt = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(map[i][j] == 0 || visited[i][j] != 0) continue;
                visited[i][j] = cnt;
                dfs(i,j,cnt);
                cnt++;
            }
        }

        int min = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(map[i][j] == 0) continue;
                boolean[][] visit = new boolean[n][n];
                min = Math.min(min, getBridgeDistance(visit,visited[i][j],i,j));
            }
        }
        System.out.println(min);

    }
}
