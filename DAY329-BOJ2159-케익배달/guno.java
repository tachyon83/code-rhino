import java.io.*;
import java.util.*;

public class Main {

    static class Point{
        int x,y;
        long dist;
        public Point(int x, int y, long dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }
    static int[] dx = {0,0,0,1,-1};
    static int[] dy = {0,1,-1,0,0};
    static int MAX = 100000;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;

        int n=Integer.parseInt(br.readLine());
        Point[] p = new Point[5];

        st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());

        for (int i = 0; i < 5; i++) {
            p[i] = new Point(x,y,0);
        }

        while (n-->0){
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            Point[] p2 = new Point[5];

            for (int i = 0; i < 5; i++) {
                int nx = x+dx[i], ny = y+dy[i];
                if(nx<0||ny<0||nx>MAX||ny>MAX)
                    continue;
                long temp = Long.MAX_VALUE;

                for (Point point : p) {
                    temp = Math.min(temp,Math.abs(point.x-nx)+Math.abs(point.y-ny)+point.dist);
                }
                p2[i] = new Point(nx,ny,temp);
            }
            for (int i = 0; i < 5; i++) {
                p[i] = p2[i];
            }

        }

        long ans = Long.MAX_VALUE;
        for (int i = 0; i < 5; i++) {
            ans = Math.min(ans, p[i].dist);
        }
        sb.append(ans);


        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
