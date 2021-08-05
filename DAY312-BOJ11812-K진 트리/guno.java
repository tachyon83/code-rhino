import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;
        st=new StringTokenizer(br.readLine());
        long n=Long.parseLong(st.nextToken()),k=Long.parseLong(st.nextToken()),q=Long.parseLong(st.nextToken());


        while (q-->0){
            st=new StringTokenizer(br.readLine());
            long a=Long.parseLong(st.nextToken()),b=Long.parseLong(st.nextToken());
            long cnt=0;
            if(k==1)
                cnt=Math.abs(a-b);
            else {
                while (a!=b){
                    if(a>b)
                        a=getParent(a,k);
                    else
                        b=getParent(b,k);
                    cnt++;
                }

            }
            sb.append(cnt).append("\n");

        }
        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

    static long getParent(long child,long k){
        return (child+k-2)/k;
    }
}
