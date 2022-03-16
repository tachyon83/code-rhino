import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;

        long t = Long.parseLong(br.readLine());
        int n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        int m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        int[] B = new int[m];
        for (int i = 0; i < m; i++) {
            B[i] = Integer.parseInt(st.nextToken());
        }

        int[] sumA = new int[n+1];
        int[] sumB = new int[m+1];

        sumA[0] = 0;
        for (int i = 1; i <= n; i++) {
            sumA[i] = sumA[i-1] + A[i-1];
        }
        sumB[0] = 0;
        for (int i = 1; i <= m; i++) {
            sumB[i] = sumB[i - 1] + B[i-1];
        }

        HashMap<Long,Long> hm = new HashMap<>();

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                long num = sumA[i] - sumA[j];
                long cnt = hm.get(num)==null? 0:hm.get(num);
                hm.put(num, cnt+1);
            }
        }

        long ans = 0;

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j < i ; j++) {
                long num = sumB[i] - sumB[j];
                long cnt = hm.get(t-num)==null? 0:hm.get(t-num);
                ans += cnt;
            }
        }

        sb.append(ans);


        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
