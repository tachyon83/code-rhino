import java.io.*;
import java.util.*;

public class Main {
    static TrieNode root=new TrieNode();
    static List<TrieNode> endList=new ArrayList<>();
    static char[][] map;
    static boolean[][] visited;
    static int[] dx={0,0,1,1,1,-1,-1,-1};
    static int[] dy={1,-1,1,0,-1,1,0,-1};
    static String longest="";
    static int sum=0;
    static int cnt=0;
    static int[] scores={0,0,0,1,1,2,3,5,11};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;
        int w=Integer.parseInt(br.readLine());
        for (int i = 0; i < w; i++) {
            String s=br.readLine();
            insert(s);
        }
        br.readLine();
        int b=Integer.parseInt(br.readLine());
        while (b-->0){
            for(TrieNode t:endList){
                t.isChecked=false;
            }
            sum=0;
            cnt=0;
            longest="";
            map=new char[4][4];
            visited=new boolean[4][4];
            for (int q = 0; q <4 ; q++) {
                String s=br.readLine();
                map[q]=s.toCharArray();
            }
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if(root.child[map[i][j]-'A']!=null)
                        search(i,j,root.child[map[i][j]-'A'],String.valueOf(map[i][j]));
                }
            }
            sb.append(sum).append(" ").append(longest).append(" ").append(cnt).append("\n");

            if(b!=0)
                br.readLine();
        }




        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }
    static class TrieNode{
        TrieNode[] child=new TrieNode[26];
        boolean isEnd,isChecked;
    }
    static void insert(String s){
        TrieNode parent=root;
        for (int i = 0; i < s.length(); i++) {
            int idx=s.charAt(i)-'A';
            if(parent.child[idx]==null){
                parent.child[idx]=new TrieNode();
            }
            parent=parent.child[idx];
        }
        parent.isEnd=true;
        endList.add(parent);
    }
    static void search(int x,int y,TrieNode current, String s){
        if(s.length()>8)
            return;


        visited[x][y]=true;
        if(current.isEnd&&!current.isChecked){
            current.isChecked=true;
            cnt++;
            if(s.length()==longest.length()){
                longest=longest.compareTo(s)<0?longest:s;
            }else if(longest.length()<s.length()){
                longest=s;
            }
            sum+=scores[s.length()];
        }

        for (int i = 0; i < 8; i++) {
            int nx=x+dx[i],ny=y+dy[i];
            if(0<=nx && nx <4 && 0<= ny && ny<4 && !visited[nx][ny] ){
                char c=map[nx][ny];
                if(current.child[c-'A']!=null)
                    search(nx,ny,current.child[c-'A'],s+map[nx][ny]);
            }
        }
        visited[x][y]=false;

    }

}
