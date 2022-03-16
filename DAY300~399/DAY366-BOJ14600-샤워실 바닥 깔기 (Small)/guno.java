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

    static int[][] block;

    public static void main(String[] args) throws Exception {

        int len = Integer.parseInt(br.readLine());
        len = len == 1 ? 2 : 4;
        getSt();
        int x = getInt(), y = getInt();
        x--;y--;
        y = len - y - 1;

        if (len == 2) {
            block = new int[][]{{1, 1}, {1, 1}};
        }else {
            block = new int[][]{{1, 1, 2, 2}, {1, 1, 3, 2}, {4, 3, 3, 5}, {4, 4, 5, 5}};
            if (x >= len / 2 && y < len / 2) {
                rotate(1);
            } else if (x >= len / 2 && y >= len / 2) {
                rotate(2);
            } else if (x < len / 2 && y >= len / 2) {
                rotate(3);
            }
        }
        block[y][x] = -1;

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                sb.append(block[i][j]).append(" ");
            }
            sb.append("\n");
        }

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


    static void rotate(int cnt) {
        for (int i = 0; i < cnt; i++) {
            int[][] temp = new int[4][4];
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    temp[k][3 - j] = block[j][k];
                }
            }
            block = temp;
        }
    }
}
