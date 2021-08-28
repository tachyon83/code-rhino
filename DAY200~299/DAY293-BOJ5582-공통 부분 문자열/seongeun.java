/**
 * LCS와 공통부분문자열의 차이
 * LCS는 가장 긴 공통 수열을 찾는 문제이지만 공통 부분 문자열은 연속되어야 한다.
 * 그래서 공통 부분 문자열은 같은 경우만 대각선 + 1을 진행해주지만
 * LCS는 이전 값도 기록하면서 가지고 와야 한다.
 */
public class 공통부분문자열_5582 {
    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String str1 = input.readLine();
        String str2 = input.readLine();
        int[][] dp = new int[str1.length() + 1][str2.length() + 1];

        int max = 0;
        for (int i = 1; i <= str1.length(); i++) {
            for ( int j = 1; j <= str2.length(); j++) {
                if(str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    max = Math.max(dp[i][j],max);
                }
            }

        }

        System.out.println(max);
    }
}
