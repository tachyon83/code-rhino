import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static class Node{
        int conNode;
        int weight;

        public Node(int conNode, int weight) {
            this.conNode = conNode;
            this.weight = weight;
        }

    }

    static ArrayList<Node> list[];
    static boolean visited[];
    static int num[];
    static int gigaNode;
    static int middle;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        int root = Integer.parseInt(st.nextToken());

        list = new ArrayList[n+1];
        visited = new boolean[n+1];
        num = new int[n+1];

        for(int i = 1 ; i <= n ; i++){
            list[i] = new ArrayList<Node>();
        }

        for(int i = 0 ; i < n-1 ; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());

            list[a].add(new Node(b,weight));
            list[b].add(new Node(a,weight));

        }
            visited[root] = true;
            gigaNode(root,0);


            if(gigaNode == 0){
                System.out.println(middle+" "+0);
            }else{


                dfs(gigaNode);

                System.out.println(middle+" "+num[gigaNode]);
            }


    }

    public static int dfs(int node){

        int sum = 0;
        for(int i = 0 ; i < list[node].size();i++){
            Node getNode = list[node].get(i);
            if(!visited[getNode.conNode]){
                visited[getNode.conNode] = true;

                sum = dfs(getNode.conNode)+ getNode.weight;
                num[node] = Math.max(num[node],sum);
            }
        }

        return num[node];
    }

    public static void gigaNode(int node,int sum){


        middle = sum;
        ArrayList<Node> conlist = new ArrayList<Node>();
        for(int i = 0 ; i < list[node].size();i++){
            Node getNode = list[node].get(i);
          

            if(!visited[getNode.conNode]){
                conlist.add(getNode);
            }
            
              if(conlist.size() >=2){
                gigaNode = node;
                return;
            }
        }

        for(Node con : conlist){
            visited[con.conNode] =true;
            gigaNode(con.conNode,sum+con.weight);
        }


    }


}
