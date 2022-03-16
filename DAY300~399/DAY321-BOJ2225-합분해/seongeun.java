
public class 합분해_2225 {

    static long dp[][];
    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(input.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        dp = new long[201][201];

        for(int i = 1; i <= 200; i++) {
            dp[i][1] = 1;
            dp[1][i] = i;
        }
        for(int i = 2; i <= n; i++) {
            for(int j = 2; j <= k; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
            }
        }
        System.out.println(dp[n][k]);
    }
}
