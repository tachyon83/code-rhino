import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static char[][] map;
    static char[] direction = {'N', 'S', 'W', 'E'};
    static int N;
    static int M;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for(int i=0; i<T; i++) {
            String[] input = br.readLine().split(" ");
            N = Integer.parseInt(input[0]);
            M = Integer.parseInt(input[1]);
            map = new char[N][M];
            Pair one = null;
            Pair two = null;

            for(int j=0; j<N; j++) {
                String str = br.readLine();
                for(int k=0; k<M; k++) {
                    map[j][k] = str.charAt(k);

                    if(map[j][k]=='P') {
                        if(one==null)
                            one = new Pair(j, k);
                        else
                            two = new Pair(j, k);

                        map[j][k] = '.';
                    }
                }
            }

            bfs(one, two);
        }
    }

    public static void bfs(Pair one, Pair two) {
        Queue<Pack> queue = new LinkedList<>();
        boolean[][][][] visited = new boolean[N][M][N][M];
        queue.add(new Pack(one, two, "", 0));

        while(!queue.isEmpty()) {
            Pack temp = queue.poll();

            if(temp.one.x==temp.two.x && temp.one.y==temp.two.y) {
                System.out.println(temp.cnt+" "+temp.path);
                return;
            }

            for(int i=0; i<4; i++) {
                int nx1 = temp.one.x + dx[i];
                int ny1 = temp.one.y + dy[i];
                int nx2 = temp.two.x + dx[i];
                int ny2 = temp.two.y + dy[i];

                if(nx1<0 || nx1>=N || ny1<0 || ny1>=M) {
                    if(nx1<0)
                        nx1 = N-1;
                    else if(nx1>=N)
                        nx1 = 0;
                    else if(ny1<0)
                        ny1 = M-1;
                    else
                        ny1 = 0;
                }

                if(nx2<0 || nx2>=N || ny2<0 || ny2>=M) {
                    if(nx2<0)
                        nx2 = N-1;
                    else if(nx2>=N)
                        nx2 = 0;
                    else if(ny2<0)
                        ny2 = M-1;
                    else
                        ny2 = 0;
                }

                if(map[nx1][ny1]=='X') {
                    nx1 = temp.one.x;
                    ny1 = temp.one.y;
                }

                if(map[nx2][ny2]=='X') {
                    nx2 = temp.two.x;
                    ny2 = temp.two.y;
                }

                if(visited[nx1][ny1][nx2][ny2] || map[nx1][ny1]=='G' || map[nx2][ny2]=='G') continue;
                visited[nx1][ny1][nx2][ny2] = true;

                queue.add(new Pack(new Pair(nx1, ny1), new Pair(nx2, ny2), temp.path+direction[i], temp.cnt+1));
            }
        }

        System.out.println("IMPOSSIBLE");
    }

    public static class Pack {
        Pair one;
        Pair two;
        String path;
        int cnt;

        public Pack(Pair one, Pair two, String path, int cnt) {
            this.one = one;
            this.two = two;
            this.path = path;
            this.cnt = cnt;
        }
    }

    public static class Pair {
        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
