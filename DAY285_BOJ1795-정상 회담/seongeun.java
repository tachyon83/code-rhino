public class 정상회담_1795 {

    private static int n,m;
    private static int[] dx = {-1, 1, 2, 2, 1, -1, -2, -2}; //상좌 상우 우상 우하 하우 하좌 좌하 좌상
    private static int[] dy = {-2, -2, -1, 1, 2, 2, 1, -1};
    private static int[][] resultKeyCount;
    private static int[][] resultMoveCount;
    private static int[][] visited;

    private static void bfs(int key, int y1, int x1) {

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{y1, x1, 0, 1});
        for(int i = 0; i < n; i++) Arrays.fill(visited[i], -1);
        visited[y1][x1] = 0;
        resultKeyCount[y1][x1]++;
        while(!q.isEmpty()) {
            int[] location = q.poll();
            int y = location[0];
            int x = location[1];
            int keyCnt = location[2]; //key control
            int moveCount = location[3]; //move count
            for (int i = 0; i < 8; i++) {
                int next_x = x + dx[i];
                int next_y = y + dy[i];
                if (next_x < 0 || next_y < 0 || next_y >= n || next_x >= m) continue;
                if (visited[next_y][next_x] != -1) continue;
                if (keyCnt == key) {
                    keyCnt = 0;
                    moveCount++;
                }
                resultKeyCount[next_y][next_x]++;
                visited[next_y][next_x] = moveCount;
                q.add(new int[]{next_y, next_x, keyCnt + 1, moveCount});
            }
        }
    }

    private static int getMinMove(int target) {
        int answer = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(resultKeyCount[i][j] == target && resultMoveCount[i][j] >= 0)
                    answer = Math.min(answer,resultMoveCount[i][j]);
            }
        }
        return answer == Integer.MAX_VALUE ? -1 : answer;
    }

    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(input.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        resultKeyCount = new int[n][m];
        resultMoveCount = new int[n][m];
        int targetCount = 0;
        for(int i = 0; i < n; i++){
            String str = input.readLine();
            for(int j = 0; j < m; j++){
                char ch = str.charAt(j);
                if(ch == '.') continue;
                visited = new int[n][m];
                bfs(ch - '0',i,j);
                for(int y = 0; y < n; y++) for (int x = 0; x < m; x++) resultMoveCount[y][x] += visited[y][x];
                targetCount++;
            }
        }

        System.out.println(getMinMove(targetCount));
    }
}
