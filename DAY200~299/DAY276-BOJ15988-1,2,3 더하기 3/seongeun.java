public class 백준_123더하기3_15988 {
    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(input.readLine());
        int[] dp = new int[1000001];
        dp[0] = 1;
        for(int j = 1; j <= 1000000; j++){
            dp[j] = (dp[j] + dp[j - 1]) % 1000000009;
            if(j >= 2) dp[j] = (dp[j] + dp[j - 2]) % 1000000009;
            if(j >= 3) dp[j] = (dp[j] + dp[j - 3]) % 1000000009;
        }
        for(int i = 1; i <= n; i++){
            int target = Integer.parseInt(input.readLine());
            sb.append(dp[target]).append("\n");
        }
        System.out.println(sb);
    }
}
