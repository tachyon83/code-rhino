import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        int h = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());

        for (int i = 0; i < h; i++) {
            String s = br.readLine();
            int cnt = -1;
            for (int j = 0; j < w; j++) {
                if(s.charAt(j)=='.' && cnt == -1){
                    sb.append(cnt).append(" ");
                    continue;
                }
                if(s.charAt(j)=='c'){
                    cnt = 0;
                }
                sb.append(cnt++).append(" ");
            }
            sb.append("\n");
        }
        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

}
