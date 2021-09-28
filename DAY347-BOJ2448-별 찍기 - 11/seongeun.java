

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.Buffer;

public class 별찍기11_2448 {

    static char[][] map;
    static int n;
    static int m;

    static void makeStar(int n, int y, int x) {

        if(n == 3) {
            drawStar(y, x);
            return;
        }

        makeStar(n / 2, y , x );
        makeStar(n / 2, y + (n / 2), x + (n / 2));
        makeStar(n / 2, y + (n / 2), x - (n / 2));
    }

    static void drawStar(int y, int x) {

        map[y][x] = '*';
        map[y + 1][x - 1] = '*';
        map[y + 1][x + 1] = '*';
        for(int i = -2; i <= 2; i++) {
            map[y + 2][x + i] = '*';
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(input.readLine());
        m = 2 * n - 1;
        map = new char[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                map[i][j] = ' ';
            }
        }

        makeStar(n, 0, n - 1);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                sb.append(map[i][j]);
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
