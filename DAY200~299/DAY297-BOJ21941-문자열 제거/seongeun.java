public class 문자열제거_21941 {

    private static String str;
    private static int n;
    private static int[] dp;
    private static HashMap<String,Integer> map;


    private static int dfs(int index) {

        if(index >= str.length()) return 0;
        if(dp[index] != 0) return dp[index];
        int maxValue = 0;

        for( String key : map.keySet()) {
            int score = map.get(key);
            if(str.startsWith(key, index))
                maxValue = Math.max(maxValue, dfs(index + key.length()) + score);
        }
        
        dp[index] = Math.max(maxValue, dfs(index + 1) + 1);
        return dp[index];
    }

    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        str = input.readLine();
        n = Integer.parseInt(input.readLine());
        map = new HashMap<>();
        dp = new int[str.length()];

        for( int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(input.readLine());
            String compareStr = st.nextToken();
            int score = Integer.parseInt(st.nextToken());
            map.put(compareStr, score);
        }

        //System.out.println(bfs());
        System.out.println(dfs(0));

    }
}
