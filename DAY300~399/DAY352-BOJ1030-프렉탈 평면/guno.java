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


    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        int s = getInt(), N = getInt(), K = getInt(), R1 = getInt(), R2 = getInt(), C1 = getInt(), C2 = getInt();

        boolean[][] isBlack = new boolean[N][N];
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                isBlack[(N - K) / 2 + i][(N - K) / 2 + j] = true;
            }
        }

        for (int i = R1; i <= R2; i++) {
            for (int j = C1; j <= C2; j++) {
                int r = i, c = j;
                boolean black = false;

                for (int k = 0; k < s; k++) {
                    if (isBlack[r % N][c % N]) {
                        black = true;
                        break;
                    }else {
                        r/=N;
                        c/=N;
                    }
                }
                if (black)
                    sb.append(1);
                else
                    sb.append(0);
            }
            sb.append("\n");
        }


        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
