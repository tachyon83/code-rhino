
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(input.readLine()); //목표 금액
        int n = Integer.parseInt(input.readLine()); //코인의 개수
        int[][] coins = new int[n + 1][2];
        int[] dp = new int[t + 1];
        dp[0] = 1;

        for(int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(input.readLine());
            coins[i][0] = Integer.parseInt(st.nextToken());
            coins[i][1] = Integer.parseInt(st.nextToken());
        }

        //코인의 수
        for(int i = 1; i <= n; i++) {
            int coin = coins[i][0];
            int count = coins[i][1];
            //해당 코인의 개수
            for(int j = t; j >= coin; j--) {
                for(int k = 1; k <= count; k++) {
                    int value = j - (coin * k);
                    if(value < 0) break;
                    dp[j] += dp[value];
                }
            }
            //display(dp);
        }

        System.out.println(dp[t]);
    }

    static void display(int[] dp) {

        StringBuilder sb = new StringBuilder();
        for(int i = 1; i < dp.length; i++) {
            sb.append(dp[i]).append(" ");
        }
        System.out.println(sb);
    }
}

