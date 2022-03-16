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

    static int[] pre;
    static int[] in;
    static List<Integer> post;
    public static void main(String[] args) throws Exception {

        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            pre = new int[n];
            in = new int[n];
            post = new ArrayList<>();
            getSt();
            for (int i = 0; i < n; i++) {
                pre[i] = getInt();
            }
            getSt();
            for (int i = 0; i < n; i++) {
                in[i] = getInt();
            }
            solve(0, n - 1, 0, n - 1);
            for (int i = post.size()-1; i >= 0; i--) {
                sb.append(post.get(i)).append(" ");
            }
            sb.append("\n");
        }

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

    static void solve(int preL, int preR, int inL, int inR) {
        if(preL>preR)
            return;
        int rootIdx = -1;
        for (int i = inL; i <= inR; i++) {
            if (in[i] == pre[preL]) {
                rootIdx = i;
                break;
            }
        }
        post.add(pre[preL]);
        int leftLen = rootIdx - inL;
        solve(preL + leftLen + 1, preR, rootIdx + 1, inR);
        solve(preL+1,preL+leftLen,inL,rootIdx-1);
    }
}
