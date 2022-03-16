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
    static void getSt() throws IOException {st = new StringTokenizer(br.readLine());}

    public static void main(String[] args) throws Exception {

        getSt();
        int d = getInt(), k = getInt();
        int[] dp = new int[d - 1];
        dp[0]=1;
        dp[1] = 1;
        for (int i = 2; i < d - 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        for (int i = 1; i < k; i++) {
            int remain = k - i * dp[d - 3];
            if (remain % dp[d - 2] == 0) {
                sb.append(i).append('\n');
                sb.append(remain / dp[d - 2]);
                break;
            }
        }

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
