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

        st = new StringTokenizer(br.readLine());
        int n = getInt(), r = getInt(), c = getInt();

        int len = (int) Math.pow(2, n);
        int ans = 0;
        while(len>=2){
            len/=2;
            int area = len * len;
            int cnt = 0;

            if(r>=len){
                r-=len;
                cnt+=2;
            }
            if(c>=len){
                c-=len;
                cnt+=1;
            }
            ans += cnt * area;
        }
        sb.append(ans);

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
