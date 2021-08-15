import java.io.*;
import java.util.*;

public class Main {

    static List<List<Integer>> graph=new ArrayList<>();
    static int[] peoples;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;
        int n=Integer.parseInt(br.readLine());
        peoples=new int[n+1];
        for (int i = 0; i < n + 1; i++) {
            graph.add(new ArrayList<>());
        }
        st=new StringTokenizer(br.readLine());
        for (int i = 1; i < n+1; i++) {
            peoples[i]=Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < n-1; i++) {
            st=new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken()),b=Integer.parseInt(st.nextToken());
            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        sb.append(dfs(1,0,false));

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

    static int dfs(int node,int parent,boolean isChecked){
        int ret=0;

        for (int next:graph.get(node)){
            int temp;
            if(next==parent){
                if(isChecked)
                    continue;
                else{
                    ret+=peoples[node];
                }


            }

            if(isChecked){
                temp=dfs(next,node,false);
            }else {
                temp=Math.max(dfs(next,node,true)+peoples[node],dfs(next,node,false));
            }
            ret+=Math.max(ret,temp);
        }
        return ret;
    }

}
