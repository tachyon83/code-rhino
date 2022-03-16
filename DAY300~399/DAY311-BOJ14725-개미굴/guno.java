
import java.io.*;
import java.util.*;

public class Main {

    static class Node{
        String val;
        List<Node> child;
        Node(String s){
            this.val=s;
            child=new ArrayList<>();
        }
    }
    static StringBuilder sb=new StringBuilder();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n=Integer.parseInt(br.readLine());
        Node root=new Node("");
        while (n-->0){

            st=new StringTokenizer(br.readLine());
            int k=Integer.parseInt(st.nextToken());
            String[] words=new String[k];
            for (int i = 0; i < k; i++) {
                words[i]=st.nextToken();
            }
            Node current=root;
            Node child=null;
            for (int i = 0; i < k; i++) {
                child=find(current,words[i]);
                if(child==null){
                    child=new Node(words[i]);
                    current.child.add(child);
                }
                current=child;
            }

        }
        root.child.sort((o1, o2) -> o1.val.compareTo(o2.val));
        for(Node node: root.child){
            dfs(node,0);
        }


        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }
    static void dfs(Node current,int depth){
        for (int i = 0; i < depth; i++) {
            sb.append("--");
        }
        sb.append(current.val).append("\n");

        current.child.sort((o1, o2) -> o1.val.compareTo(o2.val));

        for(Node node: current.child){
            dfs(node,depth+1);
        }

    }

    static Node find(Node parent,String s){
        for(Node node: parent.child){
            if(node.val.equals(s))
                return node;
        }
        return null;
    }

}
