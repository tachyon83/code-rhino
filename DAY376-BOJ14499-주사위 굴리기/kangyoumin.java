import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int[][] map = new int[20][20];
    public static int[] dice = new int[7];
    public static int[] dr = {0, 0, -1, 1}; 
    public static int[] dc = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < K; i++) {
            int d = Integer.parseInt(st.nextToken());
            int next_r = x + dr[d - 1];
            int next_c = y + dc[d - 1];

            if (next_r >= 0 && next_c >= 0 && next_r < N && next_c < M) {
                rollDice(d);

                if (map[next_r][next_c] == 0) {
                    map[next_r][next_c] = dice[6];
                } else {
                    dice[6] = map[next_r][next_c];
                    map[next_r][next_c] = 0;
                }

                x = next_r;
                y = next_c;
                System.out.println(dice[1] + "\n");
            }
        }
    }

    public static void rollDice(int d) {
        int[] temp = dice.clone();

        switch (d) {
            case 1:
                dice[1] = temp[4];
                dice[3] = temp[1];
                dice[4] = temp[6];
                dice[6] = temp[3];
                break;
            case 2:
                dice[1] = temp[3];
                dice[3] = temp[6];
                dice[4] = temp[1];
                dice[6] = temp[4];
                break;
            case 3:
                dice[1] = temp[5];
                dice[2] = temp[1];
                dice[5] = temp[6];
                dice[6] = temp[2];
                break;
            case 4:
                dice[1] = temp[2];
                dice[2] = temp[6];
                dice[5] = temp[1];
                dice[6] = temp[5];
                break;
        }
    }
}
