public class 가장큰정사각형_1915 {

    private static int getMaxSquare(int n, int m, int[][] arr) {

        int result = 0;
        int[][] dp = new int[n + 1][m + 1];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(arr[i - 1][j - 1] == 0) dp[i][j] = 0;
                else dp[i][j] = Math.min(Math.min(dp[i - 1][j],dp[i - 1][j - 1]),dp[i][j - 1]) + 1;
                result = Math.max(result,dp[i][j]);
            }
        }
        return result * result;
    }

    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(input.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] arr = new int[n][m];
        for(int i = 0; i < n; i++){
            String str = input.readLine();
            for(int j = 0; j < m; j++){
                arr[i][j] = (str.charAt(j) - '0');
            }
        }
        System.out.println(getMaxSquare(n,m,arr));
    }
}
