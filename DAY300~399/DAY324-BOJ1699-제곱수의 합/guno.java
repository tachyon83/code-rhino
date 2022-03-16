import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;
        int n=Integer.parseInt(br.readLine());
        List<Integer> nums=new ArrayList<>();
        for (int i = 1; i < 1000; i++) {
            if(i*i>n)
                break;
            else
                nums.add(i*i);
        }
        int[] dp=new int[n+1];
        Arrays.fill(dp,100000000);
        dp[0]=0;
        for (int i = 1; i < n+1; i++) {
            for(int num:nums){
                if(num>i)
                    break;
                dp[i]=Math.min(dp[i],dp[i-num]+1);
            }
        }
        sb.append(dp[n]);

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
