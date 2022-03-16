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
    static List<List<Integer>> graph = new ArrayList<>();

    public static void main(String[] args) throws Exception {

        getSt();
        int n = getInt();
        int[] scores = new int[n];
        getSt();
        for (int i = 0; i < n; i++) {
            scores[i] = getInt();
        }
        graph = new ArrayList<>();
        for (int i = 0; i < n+1; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < n-1; i++) {
            getSt();
            int a = getInt(), b = getInt();
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        sb.append(Math.max(checked(1), notChecked(1)));

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

    static int checked(int node) {
        int ret = 0;
        for (Integer child : graph.get(node)) {
            ret += notChecked(child);
        }
        return ret;
    }

    static int notChecked(int node) {
        int ret = 0;
        for (Integer child : graph.get(node)) {
            ret += checked(child);
        }
        return ret;
    }
}
