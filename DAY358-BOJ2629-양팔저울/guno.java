import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb=new StringBuilder();
    static StringTokenizer st;
    static int getInt(){
        return Integer.parseInt(st.nextToken());
    }
    static void getSt() throws IOException {st = new StringTokenizer(br.readLine());}

    public static void main(String[] args) throws Exception {

        int n = Integer.parseInt(br.readLine());
        getSt();
        int[] chus = new int[n];
        for (int i = 0; i < n; i++) {
            chus[i] = getInt();
        }
        int m = Integer.parseInt(br.readLine());
        getSt();
        int[] balls = new int[m];
        for (int i = 0; i < m; i++) {
            balls[i] = getInt();
        }
        
        int maxWeight = 500*n;
        boolean[] check =new boolean[maxWeight+1];
        boolean[] minusCheck = new boolean[501];
        check[0] = true;
        for (int chu : chus) {
            List<Integer> list = new ArrayList<>();
            for (int i = -500; i <= maxWeight; i++) {
                if (i < 0 ) {
                    if (minusCheck[-i]) {
                        list.add(i + chu);
                        if(i-chu>=-500)
                            list.add(i - chu);
                    }
                }
                else if (check[i]) {
                    if (i + chu <= maxWeight)
                        list.add(i + chu);
                    list.add(i - chu);
                }
            }
            for (Integer l : list) {
                if(l<0)
                    minusCheck[-l] = true;
                else
                    check[l] = true;
            }
        }
        for (int ball : balls) {
            if (ball > maxWeight) {
                sb.append("N").append(" ");
                continue;
            }
            if(check[ball])
                sb.append("Y").append(" ");
            else
                sb.append("N").append(" ");
        }

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
