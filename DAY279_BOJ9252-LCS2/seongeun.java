public class LCS2_9252 {

    private static void stringToCharArray(String str, char[] c){
        for(int i = 0; i < str.length(); i++) c[i + 1] = str.charAt(i);
    }
    private static void LCS(char[] c1, char[] c2) {
        StringBuilder sb = new StringBuilder();
        int[][] dp = new int[c1.length][c2.length];

        int max = -1;
        for(int i = 1; i < c1.length; i++){
            char ch = c1[i];
            for(int j = 1; j < c2.length; j++){
                if (ch == c2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        System.out.println(dp[c1.length - 1][c2.length - 1]);

        //백트래킹 하는 방법
        int i = c1.length - 1;
        int j = c2.length - 1;
        while(i != 0 && j != 0){

            if(dp[i][j] == dp[i][j - 1]) {
                j--;
            } else if(dp[i][j] == dp[i - 1][j]){
                i--;
            }
            else {
                sb.append(c1[i]);
                i--;
                j--;
            }
        }
        System.out.println(sb.reverse());

    }

    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String str1 = input.readLine();
        String str2 = input.readLine();
        char[] c1 = new char[str1.length() + 1];
        char[] c2 = new char[str2.length() + 1];
        stringToCharArray(str1,c1);
        stringToCharArray(str2,c2);
        LCS(c1,c2);
    }
}
