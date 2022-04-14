package submit;

import java.io.*;
import java.util.*;



public class jiwoong{
    static int R, C, T;
    static int[][] arr = new int[50][50];
    static List<Integer> airCleanerRows = new ArrayList<>();
    static int sumOfDust = 2;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 0; j < C; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                sumOfDust += arr[i][j];

                if (arr[i][j] == -1) {
                    airCleanerRows.add(i);
                }
            }
        }

        solution();
    }

    static void solution() {
        while (T-- > 0) {
            arr = spreadDust();

            executeAirCleaner();
        }

        System.out.println(calculateSum());
    }

    static int[][] spreadDust() {
        int[][] temp = new int[50][50];
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        for (int x = 0; x < R; x++) {
            for (int y = 0 ; y < C; y++) {
                if (arr[x][y] == -1) {
                    temp[x][y] = -1;
                    continue;
                }

                temp[x][y] += arr[x][y];

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                    if (arr[nx][ny] == -1) continue;

                    temp[nx][ny] += (arr[x][y] / 5);
                    temp[x][y] -= (arr[x][y] / 5);
                }
            }
        }

        return temp;
    }

    static void executeAirCleaner() {
        int top = airCleanerRows.get(0);

        for (int x = top - 1; x > 0; x--) {
            arr[x][0] = arr[x-1][0];
        }

        for (int y = 0; y < C - 1; y++) {
            arr[0][y] = arr[0][y+1];
        }

        for (int x = 0; x < top; x++) {
            arr[x][C-1] = arr[x+1][C-1];
        }

        for (int y = C - 1; y > 1; y--) {
            arr[top][y] = arr[top][y-1];
        }

        arr[top][1] = 0;


        int bottom = airCleanerRows.get(1);

        for (int x = bottom + 1; x < R - 1; x++) {
            arr[x][0] = arr[x+1][0];
        }

        for (int y = 0; y < C - 1; y++) {
            arr[R-1][y] = arr[R-1][y+1];
        }

        for (int x = R - 1; x > bottom; x--) {
            arr[x][C-1] = arr[x-1][C-1];
        }

        for (int y = C - 1; y > 1; y--) {
            arr[bottom][y] = arr[bottom][y-1];
        }

        arr[bottom][1] = 0;
    }

    static int calculateSum() {
        int sum = 2;

        for (int x = 0; x < R; x++) {
            for (int y = 0; y < C; y++) {
                sum += arr[x][y];
            }
        }

        return sum;
    }
}