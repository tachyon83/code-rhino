public class 유전자_dp_2306 {
    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        char[] str = input.readLine().toCharArray();
        int[][] dp = new int[501][501];
        //for(int i = 0; i < dp.length; i++) Arrays.fill(dp[i], -1);

        //조건1 : dp[start][end] = dp[start + 1][end - 1] + 2;
        //조건2 : dp[start][end] = dp[start][k] + dp[k + 1][end];
        for(int i = 1; i < str.length; i++) { //문장 전체 길이
            for( int j = 0; j + i < str.length; j ++) { //부분 문자열의 개수
                int end = j + i;

                for(int k = j; k < end; k++) {
                    dp[j][end] = Math.max(dp[j][end], dp[j][k] + dp[k + 1][end]);
                }

                if(str[j] == 'a' && str[end] == 't' || str[j] == 'g' && str[end] == 'c') {
                    dp[j][end] = Math.max(dp[j][end], dp[j + 1][end - 1] + 2);
                }
            }
        }
        System.out.println(dp[0][str.length - 1]);
    }
}
