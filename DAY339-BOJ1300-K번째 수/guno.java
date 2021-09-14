import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        int k = Integer.parseInt(br.readLine());

        int l=0,r=k;
        while (l<r){
            int mid = (l+r)/2;
            long cnt = 0;
            for (int i = 1; i <=n ; i++) {
                cnt += Math.min(n,mid/i);
            }
            if(cnt<k)
                l=mid+1;
            else
                r=mid;

        }
        sb.append(r);



        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
