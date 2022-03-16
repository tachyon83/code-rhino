import java.io.*;
import java.util.*;

public class Main {

    static class Point{
        int num;
        boolean isChange;

        public Point(int num, boolean isChange) {
            this.num = num;
            this.isChange = isChange;
        }
    }
    static int n;
    static int[] ddx = {0, 1, 0, -1};
    static int[] ddy = {1, 0, -1, 0};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        int[][] map = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        List<int[][]> q = new LinkedList<>();
        q.add(map);
        for (int i = 0; i < 5; i++) {
            List<int[][]> temp = new LinkedList<>();
            for (int[][] points : q) {
                for (int j = 0; j < 4; j++) {
                    temp.add(move(points,j));

                }
            }
            q=temp;
        }
        int ans = 0;
        for (int[][] points : q) {
            int max = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    max = Math.max(max,points[i][j]);
                }
            }
            ans = Math.max(ans, max);
        }
        sb.append(ans);

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

    static int[][] move(int[][] map,int dir){
        int[][] temp = Arrays.stream(map).map(int[]::clone).toArray(int[][]::new);

        boolean[][] isChange = new boolean[n][n];


        int dy = ddy[dir], dx = ddx[dir];

        if (dx + dy < 0) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    if(temp[x][y]==0)
                        continue;
                    int nx = x,ny = y;
                    while (true) {
                        int tempX = nx+dx, tempY = ny+dy;
                        if ( tempX<0 || tempY<0 || temp[tempX][tempY]!=0)
                            break;
                        nx=tempX;
                        ny=tempY;
                    }

                    if(nx+dx<0 || ny+dy<0)
                        continue;
                    if (temp[nx+dx][ny+dy] == temp[x][y] && !isChange[nx+dx][ny+dy]) {
                        temp[nx+dx][ny+dy] = temp[x][y] * 2;
                        isChange[nx+dx][ny+dy] = true;
                        temp[x][y] = 0;
                    } else {
                        temp[nx][ny] = temp[x][y];
                        if(nx!=x || ny!=y )
                            temp[x][y] = 0;
                    }
                }
            }
        }
        else{
            for (int x = n-1; x >=0 ; x--) {
                for (int y = n-1; y >=0 ; y--) {
                    if(temp[x][y]==0)
                        continue;
                    int nx = x,ny = y;
                    while (true) {
                        int tempX = nx+dx, tempY = ny+dy;
                        if ( tempX >= n || tempY >= n || temp[tempX][tempY]!=0)
                            break;
                        nx = tempX;
                        ny = tempY;
                    }
                    if(nx+dx>=n || ny+dy>=n)
                        continue;
                    if (temp[nx+dx][ny+dy] == temp[x][y] && !isChange[nx+dx][ny+dy]) {
                        temp[nx+dx][ny+dy] = temp[x][y] * 2;
                        isChange[nx+dx][ny+dy] = true;
                        temp[x][y] = 0;

                    } else {
                        temp[nx][ny] = temp[x][y];
                        if(nx!=x || ny!=y )
                            temp[x][y] = 0;

                    }
                }
            }
        }


//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                System.out.print(temp[i][j]+" ");
//            }
//            System.out.println();
//        }


        return temp;
    }

}
