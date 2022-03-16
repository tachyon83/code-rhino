
public class 우수마을_1949 {

    static int[] weight;
    static int[][] dp;
    static boolean[] visited;
    static ArrayList<Integer>[] tree;
    static void dfs(int index) {

        dp[index][0] = 0;
        dp[index][1] = weight[index];
        visited[index] = true;

        for( int next : tree[index]) {
            if(visited[next]) continue;
            dfs(next);
            dp[index][1] += dp[next][0];
            dp[index][0] += Math.max(dp[next][0],dp[next][1]);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        weight = new int[n + 1];
        visited = new boolean[n + 1];
        dp = new int[n + 1][2];
        tree = new ArrayList[n + 1];
        StringTokenizer st = new StringTokenizer(input.readLine());
        for(int i = 1; i <= n; i++ ) {
            weight[i] = Integer.parseInt(st.nextToken());
            tree[i] = new ArrayList<>();
        }
        for(int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(input.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            tree[start].add(end);
            tree[end].add(start);
        }

        dfs(1);
        System.out.println(Math.max(dp[1][0],dp[1][1]));
    }
}
