import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
총 K번 회전시킨 이후에 네 톱니바퀴의 점수의 합을 출력한다. 점수란 다음과 같이 계산한다.

1번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 1점
2번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 2점
3번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 4점
4번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 8점

N극은 0, S극은 1
방향이 1인 경우는 시계 방향이고, -1인 경우는 반시계 방향, 0 은 제자리

10101111
01111101
11001110
00000010
2
3 -1
1 1

10101111
01111101
11001110
00000010
1
3 -1

7
 */

/**
 * 1. 톱니바퀴 번호랑 방향 정하기
 * 2. 톱니바퀴 돌리기
 */
public class Main {


    private static char[][] wheel;
    private static int[] directionCheck;


    private static void moveWheel(int wheelNum, int direction){

        directionCheck[wheelNum] = direction;

        int left = wheelNum;
        int leftDirection = direction;
        int right = wheelNum;
        int rightDirection = direction;

        //회전할 톱니바퀴 번호랑 방향 정하기기
        //왼쪽 검사
        while(left > 0){
            if(wheel[left - 1][2] == wheel[left][6])
                break;
                leftDirection = -leftDirection;
                directionCheck[left - 1] = leftDirection;
                left--;
        }

        //오른쪽 검사
        while(right < 3){
            if(wheel[right][2] == wheel[right + 1][6])
                break;
            rightDirection = -rightDirection;
            directionCheck[right + 1] = rightDirection;
            right++;
        }

        //System.out.println(Arrays.toString(Arrays.stream(directionCheck).toArray()));
        for(int i = 0; i < 4; i++){
            char[] tmp = new char[8];
            if(directionCheck[i] == -1){ //역방향
                for(int j = 0; j < 8; j++){
                    tmp[(j - 1 + 8) % 8] = wheel[i][j];
                }
                System.arraycopy(tmp, 0, wheel[i], 0, 8);
            }else if(directionCheck[i] == 0){
                continue;
            }else{ //정방향
                for(int j = 0; j < 8; j++){
                    tmp[(j + 1 + 8) % 8] = wheel[i][j];
                }
                System.arraycopy(tmp, 0, wheel[i], 0, 8);
            }
        }
        //disple(directionCheck);
        //display(wheel);
    }

    private static void disple(int[] directionCheck) {
        StringBuilder sb= new StringBuilder();
        for(int i = 0; i < 4; i++)
            sb.append(directionCheck[i]+" ");
        System.out.println(sb);
    }

    private static void display(char[][] wheel) {

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < 4; i++) {
            for (int j = 0; j < 8; j++)
                sb.append(wheel[i][j]);
            sb.append("\n");
        }
        System.out.println(sb);
    }

    private static int calculationWheel() {
        int result = 0;
        result += wheel[0][0] == '0' ? 0: 1;
        result += wheel[1][0] == '0' ? 0: 2;
        result += wheel[2][0] == '0' ? 0: 4;
        result += wheel[3][0] == '0' ? 0: 8;
        return result;
    }

    public static void main(String[] args) throws Exception{

        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        wheel = new char[4][8];
        for(int i = 0; i < 4; i++){
            wheel[i] = input.readLine().toCharArray();
        }
        //display(wheel);
        int n = Integer.parseInt(input.readLine());

        for(int i = 0; i < n; i++){
            StringTokenizer st = new StringTokenizer(input.readLine());
            int wheelNum  = Integer.parseInt(st.nextToken());
            int direction = Integer.parseInt(st.nextToken());
            directionCheck = new int[4];
            moveWheel(wheelNum - 1,direction);
        }

        System.out.println(calculationWheel());

    }
}
