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

        int n = Integer.parseInt(br.readLine());
        int mod = 9901;
        int zero = 1, one = 2;
        for (int i = 1; i < n; i++) {
            int nZero = (zero + one) % mod, nOne = (zero * 2 + one) % mod;
            zero = nZero;
            one = nOne;
        }
        sb.append((zero + one) % mod);

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
