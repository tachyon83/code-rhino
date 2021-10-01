import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb=new StringBuilder();
    static StringTokenizer st;
    static int getInt(){
        return Integer.parseInt(st.nextToken());
    }

    public static void main(String[] args) throws Exception {

        int t = Integer.parseInt(br.readLine());
        int k = Integer.parseInt(br.readLine());

        List<Integer>[] coins=new List[k];

        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            coins[i] = new ArrayList<>();
            int price = getInt(), cnt = getInt();
            for (int j = 1; j <= cnt; j++) {
                coins[i].add(price * j);
            }
        }

        int[] dp = new int[t + 1];
        dp[0] = 1;
        for (List<Integer> coin : coins) {

            for (int i = t-1; i >=0 ; i--) {
                for (Integer price : coin) {
                    if(i+price<=t){
                        dp[i + price] += dp[i];
                    }
                }
            }

        }
        sb.append(dp[t]);

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
