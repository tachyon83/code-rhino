

/**
 * 1. 섬의 개수를 파악한다.
 * 2. 다리의 개수가 섬의 개수 - 1개보다 작다면 만들 수 없는 것이다.
 * 3. 섬들 간의 모든 다리를 놓으면서 기록한다.
 * 4. 다리들은 검사하면서 최소가 되면서 조건을 만족하는
 * 다리들은 찾는다.
 */
public class 다리만들기2_17272 {

    private static int n;
    private static int m;
    private static int[] parent;
    private static int[][] map;
    private static int[][] island;
    private static int[][] bridge;
    private static int[] dx = {0, 0, -1, 1}; //상하좌우
    private static int[] dy = {-1, 1, 0, 0};
    private static PriorityQueue<int[]> pq;

    private static void setIsland(int y, int x, int cnt) {


        island[y][x] = cnt;

        for(int i = 0; i < 4; i++) {
            int next_y = y + dy[i];
            int next_x = x + dx[i];
            if(next_y < 0 || next_x < 0 || next_y >= n || next_x >= m) continue;
            if(map[next_y][next_x] == 0 || island[next_y][next_x] != 0) continue;
            setIsland(next_y,next_x,cnt);
        }
    }

    private static void setBridge(int y, int x) {

        int islandNumber = island[y][x];
        for(int i = 0; i < 4; i++) {
            int cnt = 0;
            int next_y = y + dy[i];
            int next_x = x + dx[i];
            while(true) {
                if (next_x < 0 || next_y < 0 || next_y >= n || next_x >= m) break;
                if ( island[next_y][next_x] == 0) {
                    cnt++;
                    next_y += dy[i];
                    next_x += dx[i];
                } else if ( island[next_y][next_x] != islandNumber) {
                    if(cnt <= 1) break;
                    pq.add(new int[]{islandNumber,island[next_y][next_x],cnt});
                    //bridge[islandNumber][island[next_y][next_x]] = cnt;
                    break;
                } else {
                    break;
                }
            }
        }
    }

    private static int find(int index) {
        if(index == parent[index]) return index;
        return find(parent[index]);
    }

    private static void union(int start, int end) {

        int startRoot = find(start);
        int endRoot = find(end);
        if(startRoot < endRoot) parent[endRoot] = startRoot;
        else parent[startRoot] = endRoot;
    }

    public static void main( String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(input.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        island = new int[n][m];
        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(input.readLine());
            for(int j = 0; j < m ; j ++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        //섬의 개수 구하기
        int islandCount = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) {
                if(map[i][j] == 1 && island[i][j] == 0) {
                    setIsland(i,j, islandCount++);
                }
            }
        }

        pq = new PriorityQueue<>((o1, o2) -> o1[2] - o2[2]);
        parent = new int[islandCount];
        for(int i = 1; i < islandCount; i++) parent[i] = i;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(island[i][j] == 0) continue;
                setBridge(i,j);
            }
        }

        int result = 0;
        int cnt = 0;
        while(!pq.isEmpty()) {

            int[] node = pq.poll();

            int start = find(node[0]);
            int end = find(node[1]);
            if(start == end) continue;
            union(start,end);
            cnt++;
            result += node[2];
        }

        System.out.println(cnt == islandCount - 2 ? result : - 1);

    }
}
