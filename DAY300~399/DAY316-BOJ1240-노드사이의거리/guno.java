import java.io.*;
import java.util.*;

public class Main {
    static List<List<Edge>> graph;
    static boolean[] visited;
    static int ans;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;

        st=new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken()),m=Integer.parseInt(st.nextToken());
        graph=new ArrayList<>();
        for (int i = 0; i < n+1; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < n-1; i++) {
            st=new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken()),b=Integer.parseInt(st.nextToken()),c=Integer.parseInt(st.nextToken());
            graph.get(a).add(new Edge(b,c));
            graph.get(b).add(new Edge(a,c));
        }
        for (int i = 0; i < m; i++) {
            st=new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken()),b=Integer.parseInt(st.nextToken());
            visited=new boolean[n+1];
            search(a,b,0);
            sb.append(ans).append("\n");
        }


        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }
    static void search(int start,int end,int sum){
        if(start==end){
            ans=sum;
            return;
        }
        visited[start]=true;

        for(Edge e:graph.get(start)){
            if(!visited[e.to]){
                search(e.to,end,sum+e.w);
            }
        }

        visited[start]=false;

    }

    static class Edge{
        int to;
        int w;
        Edge(int to,int w){
            this.to=to;
            this.w=w;
        }
    }

}
