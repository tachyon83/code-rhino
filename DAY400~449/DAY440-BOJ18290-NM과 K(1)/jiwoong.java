import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;


public class jiwoong {
    static int[][] map;
    static boolean[][] visited;
    static int n,m,k;
    static int max = Integer.MIN_VALUE;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    public static void main(String []args) throws Exception{
        BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        map = new int[n][m];
        visited = new boolean[n][m];

        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<m;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        DFS(0,0,0,0);
        bw.write(max+"");
        bw.flush();
        bw.close();
    }

    static public void DFS(int x, int y, int sum, int count){

        if(count==k){
            max= Math.max(sum,max);
            return;
        }

        for(int i=x;i<n;i++){
            for(int j=(x==i)? y:0;j<m;j++){
                if(!visited[i][j]){
                    boolean canGo = true;
                    for(int p=0;p<4;p++){
                        int nx = x+dx[p];
                        int ny = y+dy[p];
                        if(insideMap(nx,ny) && visited[nx][ny]) {
                            canGo = false;
                        }
                    }
                    if(canGo){
                        visited[i][j] = true;
                        DFS(i,j,sum+map[i][j],count+1);
                        visited[i][j] = false;
                    }
                }

            }

        }

    }

    static boolean insideMap(int x, int y){
        if(x<0||y<0||x>=n||y>=m) return false;
        return true;
    }
}