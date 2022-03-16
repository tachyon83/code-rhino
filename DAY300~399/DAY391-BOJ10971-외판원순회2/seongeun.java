
public class 외판원순회2_10971 {

    static int n;
    static int[][] arr;
    static boolean[] visited;
    static int min = Integer.MAX_VALUE;

    private static void dfs(int index, int cnt, int sum) {
        if(cnt == n) {
            if(arr[index][0] > 0) {
                min = Math.min(min, sum + arr[index][0]);
            }
            return;
        }

        for(int i = 0; i < n; i++) {
            if(arr[index][i] == 0 || visited[i]) continue;
            visited[i] = true;
            dfs(i, cnt + 1, sum + arr[index][i]);
            visited[i] = false;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(input.readLine());
        arr = new int[n][n];
        visited = new boolean[n];
        for(int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(input.readLine());
            for(int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        visited[0] = true;
        dfs(0,1,0);

        System.out.println(min);
    }
}
