import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
 
public class Main {
 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
 
        int L = Integer.parseInt(st.nextToken());
        int W = Integer.parseInt(st.nextToken());
        int H = Integer.parseInt(st.nextToken());
 
        int N = Integer.parseInt(br.readLine());
 
        int[] cube = new int[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            int f = Integer.parseInt(st.nextToken());
 
            cube[t] = f;
        }
 
        long before = 0;
        long ans = 0;
        for (int i = N - 1; i >= 0; i--) { 
            before <<= 3;
            long possibleCube = (long) (L >> i) * (W >> i) * (H >> i) - before;
            long newCube = Math.min((long) cube[i], possibleCube); 
            before += newCube;
            ans += newCube;
        }
 
        if (before == (long) L * W * H) { 
            bw.write(ans + "\n");
        } else { 
            bw.write("-1\n");
        }
 
        bw.flush();
        bw.close();
        br.close();
    }
 
}
