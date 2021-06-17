public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        long[] dp = new long[n + 1];
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i - 1] + 1;
            if(i > 6){
                dp[i] = Math.max(dp[i],dp[i - 3] * 2);
                dp[i] = Math.max(dp[i],dp[i - 4] * 3);
                dp[i] = Math.max(dp[i],dp[i - 5] * 4);
            }
        }
        System.out.println(dp[n]);
    }
}
