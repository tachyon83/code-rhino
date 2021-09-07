
public class 배열에서이동_1981 {

    static int[][] arr;
    static boolean[][] visited;
    static int[] dx = {0, 1, 0, -1}; //상, 우, 하, 좌
    static int[] dy = {-1, 0, 1, 0}; //상, 우, 하, 좌
    static int n;
    static Set<Integer> set = new HashSet<>();
    static ArrayList<Integer> list = new ArrayList<>();

    static boolean bfs(int minValue, int maxValue) {

        if (arr[0][0] < minValue || arr[0][0] > maxValue) {
            return false;
        }

        visited = new boolean[n][n];
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0}); // y, x, max 값, max - min의 최소값
        visited[0][0] = true;

        while(!q.isEmpty()) {

            int[] node = q.poll();
            int y = node[0];
            int x = node[1];

            if (y == n - 1 && x == n - 1) {
                return true;
            }
            for (int i = 0; i < 4; i++) {
                int next_y = y + dy[i];
                int next_x = x + dx[i];
                if (next_y < 0 || next_x < 0 || next_y >= n || next_x >= n || visited[next_y][next_x]) continue;
                if (arr[next_y][next_x] < minValue || arr[next_y][next_x] > maxValue) continue;
                visited[next_y][next_x] = true;
                q.add(new int[]{next_y, next_x});
            }
        }

        return false;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(input.readLine());
        arr = new int[n][n];

        for(int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(input.readLine());
            for(int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                set.add(arr[i][j]);
            }
        }


        list.addAll(set);
        Collections.sort(list);

        //중복없이 오름차순 정렬

        int idx1 = 0;
        int idx2 = 0;
        int end = list.size();
        int result = 201;

        while(idx1 < end && idx2 < end) {

            int minValue = list.get(idx1);
            int maxValue = list.get(idx2);


            boolean check = bfs(minValue, maxValue);


            if(check) {
                result = Math.min(result, maxValue - minValue);

                idx1++;
            } else {
                idx2++;
            }
        }
        System.out.println(result);

    }
}
