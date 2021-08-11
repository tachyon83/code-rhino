import java.io.*;
import java.util.*;

public class Main {
    static int[] parents;
    static int[] colors;
    static int[] marked;
    static int k=0;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken()),m=Integer.parseInt(st.nextToken());
        parents=new int[n];
        colors=new int[n];
        marked=new int[n];

        for (int i = 0; i < m; i++) {

            st = new StringTokenizer(br.readLine());
            int r,a,b,c;
            r=Integer.parseInt(st.nextToken());
            a=Integer.parseInt(st.nextToken());
            b=Integer.parseInt(st.nextToken());

            switch (r){
                case 1:
                    c=Integer.parseInt(st.nextToken());
                    paint(a,b,c);
                    break;
                case 2:
                    move(a,b);
                    break;
                case 3:
                    sb.append(count(a,b)).append("\n");
            }
        }

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }
    static int getLca(int a,int b){
        k++;
        while (true){
            if(marked[a]==k && a!=0)
                return a;
            if(marked[b]==k && b!=0)
                return b;
            marked[a]=k;
            marked[b]=k;
            if(a==b)
                return a;
            a=parents[a];
            b=parents[b];
        }
    }
    static void paint(int a,int b,int c){
        int lca=getLca(a,b);
        while (a!=lca){
            colors[a]=c;
            a=parents[a];
        }
        while (b!=lca){
            colors[b]=c;
            b=parents[b];
        }

    }

    static void move(int a,int b){
        parents[a]=b;
    }

    static int count(int a,int b){
        Set<Integer> set=new TreeSet<>();
        int lca=getLca(a,b);
        while (a!=lca){
            set.add(colors[a]);
            a=parents[a];
        }
        while (b!=lca){
            set.add(colors[b]);
            b=parents[b];
        }

        return set.size();
    }

}
