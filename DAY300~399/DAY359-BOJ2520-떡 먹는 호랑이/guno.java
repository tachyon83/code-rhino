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
        int n = getInt(), m = getInt();
        int[] a = new int[n+1];
        int[] b = new int[n+1];
        a[1] = 1;
        a[2] = 0;
        b[1] = 0;
        b[2] = 1;
        for (int i = 3; i < n+1; i++) {
            a[i] = a[i - 1] + a[i - 2];
            b[i] = b[i - 1] + b[i - 2];
        }
        int x = a[n], y = b[n];
        int A = 0, B = 0;
        while (true) {
            if ((m - x * A) % y == 0) {
                B = (m - x * A) / y;
                break;
            }
            A++;
        }
        sb.append(A).append("\n").append(B);

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
