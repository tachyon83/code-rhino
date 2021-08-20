
public class 줄세우기_2631 {

    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        int[] arr = new int[n + 1];
        int[] dp = new int[n + 1];
        for(int i = 1; i <= n; i++) arr[i] = Integer.parseInt(input.readLine());
        Arrays.fill(dp,1);

        int max = 0;
        //최장 증가하는 수열 구하기
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                if(arr[j] < arr[i] && dp[j] >= dp[i]) {
                    dp[i] = dp[j] + 1;
                    max = Math.max(max, dp[i]);
                }
            }
        }
        System.out.println(n - max);
    }
}
