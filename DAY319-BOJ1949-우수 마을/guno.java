import java.io.*;
import java.util.*;

public class Main {
    static List<List<Integer>> graph=new ArrayList<>();
    static int[][] dp;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;
        int n=Integer.parseInt(br.readLine());
        dp=new int[n+1][2];
        for (int i = 0; i < n + 1; i++) {
            graph.add(new ArrayList<>());
        }
        st=new StringTokenizer(br.readLine());
        for (int i = 1; i < n+1; i++) {
            dp[i][1]=Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < n-1; i++) {
            st=new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken()),b=Integer.parseInt(st.nextToken());
            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        dfs(1,0);
        sb.append(Math.max(dp[1][1],dp[1][0]));

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

    static void dfs(int node,int parent){
        for (int next:graph.get(node)){
            if(next==parent){
                continue;
            }
            dfs(next,node);
            dp[node][0]+=Math.max(dp[next][0],dp[next][1]);
            dp[node][1]+=dp[next][0];
        }
    }

}
