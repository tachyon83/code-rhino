import java.io.*;
import java.util.*;

public class Main {
    static class Point{
        int x,y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int n;
    static int[][] map;
    static int[] dx = {0,0,1,-1};
    static int[] dy = {1,-1,0,0};
    static ArrayList<Integer> s = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        map = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                int temp = Integer.parseInt(st.nextToken());
                map[i][j] = temp;
                if (!s.contains(temp)) {
                    s.add(temp);
                }
            }
        }

        s.sort((o1, o2) -> o1-o2);

        int l=0,r=0,ans=Integer.MAX_VALUE;

        while (l<s.size()){
            int low = s.get(l), high = s.get(r);
            if( high-low>ans || isPossible(low,high)) {
                ans = Math.min(ans,high-low);
                l++;
            }else if(r<s.size()-1) {
                r++;
            }else
                break;
        }
        sb.append(ans);


        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

    static boolean isPossible(int low, int high){
            if(map[0][0]<low || map[0][0]>high)
                return false;
            boolean[][] visited = new boolean[n][n];
            visited[0][0] = true;

            Queue<Point> q = new LinkedList<>();
            q.add(new Point(0,0));

            while (!q.isEmpty()) {
                Point now = q.poll();
                int x = now.x , y = now.y;
                if(x==n-1 && y==n-1)
                    return true;

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny]) {
                        continue;
                    }
                    if (map[nx][ny] <= high && map[nx][ny] >= low) {
                        visited[nx][ny] = true;
                        q.add(new Point(nx,ny));
                    }
                }

            }

        return false;
    }

}
