// 2210번 숫자판 점프(silver 2)

// 제출 결과 [메모리: 28020KB 시간: 1320ms]
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class BJ_2210 {
    static String[][] map = new String[5][5];
    static int[][] check = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    static List<String> maked = new ArrayList<>();

    public static void dfs(String digit, int x , int y){
        if(digit.length() > 6)
            return;

        if(digit.length() == 6){
            if(!maked.contains(digit)){
                maked.add(digit);
                return;
            }
        }

        for (int i = 0; i < 4; i++) {
            int dx = x + check[i][0];
            int dy = y + check[i][1];

            if (0 <= dx && dx < 5 && 0 <= dy && dy < 5) {
                dfs(digit+map[x][y], dx, dy);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 0; i < 5; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < 5; j++) {
                map[i][j] = input[j];
            }
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                String digit = "";
                dfs(digit,i, j);
            }
        }

        System.out.println(maked.size());
    }
}
