import java.io.*;
import java.util.*;

public class Main {

    static int[] cnts;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());

        int[] times = new int[m];
        st = new StringTokenizer(br.readLine());
        cnts = new int[31];
        for (int i = 0; i < m; i++) {
            times[i] = Integer.parseInt(st.nextToken());
            cnts[times[i]]++;
        }
        if(n<=m){
            sb.append(n);
        }else{
            long l =0 , r = (long) (Math.ceil((double) n/m)*30);
            while (l<r){
                long mid = (l+r)/2;
                long sum = count(mid);
                if(sum<n)
                    l = mid+1;
                else
                    r = mid;
            }

            long a = count(l)-n+1;
            for (int i = m - 1; i >= 0; i--) {
                if(l%times[i]==0)
                    a--;
                if (a == 0) {
                    sb.append(i+1);
                    break;
                }
            }
        }


        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

    static long count(long mid){
        long sum = 0;
        for (int i = 1; i <= 30; i++) {
            if (cnts[i] != 0) {
                sum += (mid / i + 1) * cnts[i];
            }
        }
        return sum;
    }
}
