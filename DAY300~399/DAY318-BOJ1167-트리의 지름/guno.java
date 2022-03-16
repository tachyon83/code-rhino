import java.io.*;
import java.util.*;

public class Main {
    static class Edge{
        int to,w;

        public Edge(int to, int w) {
            this.to = to;
            this.w = w;
        }
    }

    static List<List<Edge>> graph=new ArrayList<>();
    static boolean[] visited;
    static int maxDist=0,maxIdx=1;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;

        int v=Integer.parseInt(br.readLine());
        for (int i = 0; i < v+1; i++) {
            graph.add(new ArrayList<>());
        }
        visited=new boolean[v+1];

        for (int q = 0; q < v; q++) {
            st=new StringTokenizer(br.readLine());
            List<Edge> now=graph.get(Integer.parseInt(st.nextToken()));
            while (true){
                int a=Integer.parseInt(st.nextToken());
                if(a==-1)
                    break;
                int b=Integer.parseInt(st.nextToken());
                now.add(new Edge(a,b));
            }
        }
        dfs(1,0);
        maxDist=0;
        Arrays.fill(visited,false);
        dfs(maxIdx,0);
        sb.append(maxDist);
        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }
    static void dfs(int node,int sum){
        visited[node]=true;
        if(sum>maxDist){
            maxDist=sum;
            maxIdx=node;
        }
        for(Edge e:graph.get(node)){
            if(!visited[e.to])
                dfs(e.to,sum+e.w);
        }
    }
}
