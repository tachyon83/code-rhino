/*
 * 백트래킹으로 돌아가는 경우의 수는 계산했지만 아직 백트래킹을 적용하면서 재귀로 돌리는 것을 못하는 것 같습니다.
/* 조금 더 연습해보면서 감을 잡아야 할 것 같습니다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ_2580 {

    static int[][] map = new int[9][9];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean flag = false;

        for (int i = 0; i < 9; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < 9; j++) {
                map[i][j] = Integer.parseInt(input[j]);
            }
        }

        while(!flag){
            flag = true;
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if(map[i][j] == 0){
                        flag = false;
                        fill(i, j);
                    }
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }
    }

    private static void fill(int x, int y) {
        for (int i = 1; i <= 9; i++) {
            if(possibility(x, y, i)){
                map[x][y] = i;
            }
        }
        map[x][y] = 0;
    }

    public static boolean possibility(int x, int y, int value){

        int area_x = (x / 3) * 3;
        int area_y = (y / 3) * 3;

        // 가로에 겹치는 게 있는 지
        for (int i = 0; i < 9; i++) {
            if(map[x][i] == value)
                return false;
        }

        // 세로에 겹치는 게 있는 지
        for (int i = 0; i < 9; i++) {
            if(map[i][y] == value)
                return false;
        }

        // 3*3에 겹치는 게 있는 지
        for (int i = area_x; i < area_x + 3; i++) {
            for (int j = area_y; j < area_y + 3; j++) {
                if(map[i][j] == value){
                    return false;
                }
            }
        }

        return true;
    }
}
