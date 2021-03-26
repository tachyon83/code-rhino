// 14889번 스타트와 링크(silver 3)

// 제출 결과: [메모리: 18836KB, 시간: 380ms]
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ_14889 {

    static int[][] map;
    static boolean[] visit;
    static int n;
    static int forceDiff = Integer.MAX_VALUE;

    static void backtracking(int idx, int count) {
        if (count == n / 2) {
            int startForce = 0;
            int linkForce = 0;
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (visit[i] == true && visit[j] == true) {
                        startForce += map[i][j];
                        startForce += map[j][i];
                    } else if (visit[i] == false && visit[j] == false) {
                        linkForce += map[i][j];
                        linkForce += map[j][i];
                    }
                }
            }
            forceDiff = Math.min(forceDiff, Math.abs(startForce - linkForce));
            return;
        }

        for (int i = idx; i < n; i++) {
            if (!visit[i]) {
                visit[i] = true;
                backtracking(i + 1, count + 1);
                visit[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        map = new int[n][n];
        visit = new boolean[n];

        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(input[j]);
            }
        }

        backtracking(0, 0);
        System.out.println(forceDiff);
    }


}
