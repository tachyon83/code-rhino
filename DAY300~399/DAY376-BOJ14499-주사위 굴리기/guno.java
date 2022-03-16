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

    static class Dice{
        int top,bottom,front,back,left,right;

        void moveEast() {
            int t = top, b = bottom, l = left, r = right;
            right = t;
            bottom = r;
            left = b;
            top = l;
        }

        void moveWest() {
            int t = top, b = bottom, l = left, r = right;
            left = t;
            bottom = l;
            right = b;
            top = r;
        }

        void moveNorth() {
            int t = top, bo = bottom, ba = back, f = front;
            top = f;
            front = bo;
            bottom = ba;
            back = t;
        }
        void moveSouth() {
            int t = top, bo = bottom, ba = back, f = front;
            top = ba;
            front = t;
            bottom = f;
            back = bo;
        }

    }

    public static void main(String[] args) throws Exception {
        getSt();
        int n = getInt(), m = getInt(), x = getInt(), y = getInt(), k = getInt();
        Dice dice = new Dice();
        int[][] map = new int[n][m];
        for (int i = 0; i < n; i++) {
            getSt();
            for (int j = 0; j < m; j++) {
                map[i][j] = getInt();
            }
        }
        getSt();
        for (int i = 0; i < k; i++) {
            int move = getInt();
            boolean canMove = false;

            if (move == 1 && y < m - 1) {
                y++;
                dice.moveEast();
                canMove = true;
            } else if (move == 2 && y > 0) {
                y--;
                dice.moveWest();
                canMove = true;
            } else if (move == 3 && x > 0) {
                x--;
                dice.moveNorth();
                canMove = true;
            } else if (move == 4 && x < n - 1) {
                x++;
                dice.moveSouth();
                canMove = true;
            }
            if (canMove) {
                if (map[x][y] == 0) {
                    map[x][y] = dice.bottom;
                } else {
                    dice.bottom = map[x][y];
                    map[x][y] = 0;
                }
                sb.append(dice.top).append("\n");
            }
        }
        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }
}
