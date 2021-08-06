import java.io.*;
import java.util.*;

public class Main {

    static class Node{
        boolean isEnd=false;
        int childCnt=0;
        Node[] child=new Node[26];
    }
    static Node root;
    static int sum;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();

        String line;
        while((line=br.readLine())!=null){
            root=new Node();
            sum=0;
            int n=Integer.parseInt(line);
            for (int i = 0; i < n; i++) {
                String word=br.readLine();
                Node current=root;
                for (int j = 0; j < word.length(); j++) {
                    int idx=word.charAt(j)-'a';
                    if(current.child[idx]==null){
                        current.child[idx]=new Node();
                        current.childCnt++;
                    }
                    current=current.child[idx];
                }
                current.isEnd=true;
            }
            for(Node c:root.child){
                if(c!=null)
                    dfs(c,1);
            }
            double ans=(double)sum / n;
            sb.append(String.format("%.2f", ans)).append("\n");
        }

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

    static void dfs(Node current,int cnt){
        if(current.isEnd)
            sum+=cnt;
        for (Node c:current.child){
            if(c!=null){
                if(current.isEnd||current.childCnt>1)
                    dfs(c,cnt+1);
                else
                    dfs(c,cnt);
            }
        }

    }

}
