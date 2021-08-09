import java.io.*;
import java.util.*;

public class Main {
    static Node root=new Node();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;

        st=new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken()),m=Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            String word=br.readLine();
            Node current=root;
            for (int j = 0; j < word.length(); j++) {
                int c=word.charAt(j)-'a';
                if(current.children[c]==null)
                    current.children[c]=new Node();
                current=current.children[c];
            }
            current.isEnd=true;
        }
        int cnt=0;
        for (int i = 0; i < m; i++) {
            String word=br.readLine();
            if(search(word))
                cnt++;
        }
        sb.append(cnt);


        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

    static class Node{
        boolean isEnd=false;
        Node[] children=new Node[26];
    }

    static boolean search(String word){
        Node current=root;
        for (int i = 0; i < word.length(); i++) {
            int c=word.charAt(i)-'a';
            if(current.children[c]==null)
                return false;
            current=current.children[c];
        }
        return current.isEnd;
    }

}
