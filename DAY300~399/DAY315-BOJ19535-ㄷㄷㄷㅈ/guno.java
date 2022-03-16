import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;

        int n=Integer.parseInt(br.readLine());
        int[] cnts=new int[n+1];
        List<List<Integer>> child=new ArrayList<>();
        for (int i = 0; i < n+1; i++) {
            child.add(new ArrayList<>());
        }

        for (int i = 0; i < n-1; i++) {
            st=new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken()),b=Integer.parseInt(st.nextToken());
            cnts[a]++;
            cnts[b]++;
            child.get(a).add(b);
            child.get(b).add(a);
        }
        long D=0,G=0;
        for(int num:cnts){
            if(num>=3){
                G+= (long) num *(num-1)*(num-2)/6;
            }
        }
        for (int u = 1; u <= n; u++) {
            for(int v:child.get(u)){
                if(u<v){
                    D+=(long) (cnts[u]-1)*(cnts[v]-1);
                }
            }
        }
        if(D>G*3)
            sb.append("D");
        else if(D<G*3)
            sb.append("G");
        else
            sb.append("DUDUDUNGA");

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
