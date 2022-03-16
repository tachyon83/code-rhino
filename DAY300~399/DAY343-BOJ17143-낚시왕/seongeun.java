

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

/*
4 6 8
4 1 3 3 8
1 3 5 2 9
2 4 8 4 1
4 5 0 1 4
3 3 1 2 7
1 5 8 4 3
3 6 2 1 2
2 2 2 3 5
r,c 상어의 위치
s는 속력
d는 이동방향 , 위 1, 아래 2, 오른쪽 3, 왼쪽 4
z는 크기
 */

/**
 * 상어가 벽에 도착하면 반대 방향으로 이동한다.
 */
public class 낚시왕_17143 {

    static int n, m, t;
    static HashMap<Integer, int[]> map = new HashMap<>();
    static int[][] check;
    static int result = 0;

    static void display() {
        StringBuilder sb = new StringBuilder();
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                sb.append(check[i][j]).append(" ");
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
    static void removeShark(int idx) {

        //행에서 가장 가까운 상어 지우기
        for( int i = 1; i <= n; i++) {
            if( check[i][idx] == 0) continue;
            result += check[i][idx];
            map.remove(check[i][idx]);
            check[i][idx] = 0;
            break;
        }
    }

    private static void moveShark() {

        //무게로 정렬한다.
        //이동시킨다. 이미 check에 포함되어 있으면 삭제.
        int[][] temp = new int[n + 1][m + 1];
        Queue<Integer> q = new LinkedList<>();
        for(int key : map.keySet()) {
            int[] shark = map.get(key);
            int r = shark[0];
            int c = shark[1];
            int s = shark[2];
            int d = shark[3];
            int z = shark[4];
            check[r][c] = 0;

            //s의 최대 크기는 1000이기 때문에 모듈러 연산을 해준다.
            if(d==1 || d==2) {      // 위아래만 고려
                s = s % ((n - 1) * 2);
            }
            else {  // 좌우만 고려
                s = s % ((m - 1) * 2);
            }

            if( d == 1 || d == 2) {
                for(int j = 0; j < s; j++) {
                    if( d == 1 && r == 1) {
                        d = 2;
                    }
                    if( d == 2 && r == n) {
                        d = 1;
                    }
                    if(d == 1) r--;
                    if(d == 2) r++;
                }
            } else {
                for(int j = 0; j < s; j++) {

                    if( d == 3 && c == m) {
                        d = 4;
                    }
                    if( d == 4 && c == 1) {
                        d = 3;
                    }

                    if(d == 3) c++;
                    if(d == 4) c--;
                }
            }

            map.put(z, new int[]{r,c,s,d,z});

            //상어 이동 및 상어가 먹힌 여부 확인
            if(temp[r][c] == 0) {
                temp[r][c] = z;
            } else if(temp[r][c] < z) {
                q.add(temp[r][c]);
                temp[r][c] = z;
            } else {
                q.add(z);
            }
        }

        //패배한 상어 지우기
        while(!q.isEmpty()){
            map.remove(q.poll());
        }

        //check 배열 초기화
        for(int key : map.keySet()) {
            int[] shark = map.get(key);
            int y = shark[0];
            int x = shark[1];
            //System.out.println(y + " " + x + " " + shark[4]);
            check[y][x] = temp[y][x];
        }

    }

    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(input.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        t = Integer.parseInt(st.nextToken());

        check = new int[n + 1][m + 1];
        //상어 데이터 저장
        for(int i = 0; i < t; i++) {
            st = new StringTokenizer(input.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());

            //크기 순으로 정렬
            map.put(z, new int[]{r, c, s, d, z});
            check[r][c] = z;
        }

        for(int i = 1; i <= m; i++) {
            removeShark(i);
            moveShark();
        }

        System.out.println(result);
    }
}
