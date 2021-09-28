

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

/*
6
10 20 10 30 20 50
 */
public class 가장긴증가하는부분수열4_14002 {
    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(input.readLine());
        int[] arr = new int[n + 1];
        int[] check = new int[n + 1];
        int[] dp = new int[n + 1];
        int idx = -1;
        int max = -1;
        StringTokenizer st = new StringTokenizer(input.readLine());
        for(int i = 1; i <= n; i++) arr[i] = Integer.parseInt(st.nextToken());

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[i] > arr[j] && dp[i] <= dp[j]) {
                    dp[i] = dp[j] + 1;
                    check[i] = j;
                    if(max < dp[i]) {
                        max = dp[i];
                        idx = i;
                    }
                }
            }
        }

        ArrayList<Integer> list = new ArrayList<>();
        while(idx != 0) {
            int val = arr[idx];
            list.add(val);
            idx = check[idx];
        }

        for(int i = list.size() - 1; i >= 0; i--) {
            sb.append(list.get(i)).append(" ");
        }
        System.out.println(max);
        System.out.println(sb);
    }
}
