import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        int arr[] = new int[n + 1];
        int dp[] = new int[n + 1];
        int result = 0;

        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i = 1; i <= n; i++){
            int num = Integer.parseInt(st.nextToken());
            arr[i] = num;
            for(int j = 0 ; j < i; j++){
                if(arr[i] > arr[j]){
                   dp[i] = Math.max(dp[j] + 1, dp[i]);
                   result = Math.max(dp[i], result);
                }
            }
        }
        sb.append(result + "\n");

        int value = result;
        Stack<Integer> stack = new Stack<>();

        for(int i = n; i >= 1; i--){
            if(value == dp[i]) {
                stack.push(arr[i]);
                value--;
            }
        }

        while (!stack.isEmpty()){
            sb.append(stack.pop() + " ");
        }

        bw.write(sb.toString());

        bw.close();
        br.close();
     }
}
