import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class Main {
    static int[][] map;
    static int[][] tempMap;
    static boolean[][] visited;
    static int n,m;
    static int[] dx={0,0,1,-1},dy={1,-1,0,0};
    static int answer=0;
    static List<Point> blanks=new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        StringTokenizer st=new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());

        map=new int[n][m];

        for (int i = 0; i < n; i++) {
            st=new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                int k=Integer.parseInt(st.nextToken());
                if(k==0){
                    blanks.add(new Point(i,j));
                }
                map[i][j]=k;
            }
        }
        tempMap= Arrays.stream(map).map(int[]::clone).toArray(int[][]::new);

        comb(-1,blanks.size(),new ArrayList<Integer>());

        System.out.print(answer);

    }
    static int count(){
        visited=new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(!visited[i][j] && map[i][j]==2){
                    Queue<Point> q=new LinkedList<>();
                    q.add(new Point(i,j));
                    visited[i][j]=true;

                    while (!q.isEmpty()){
                        Point p=q.poll();
                        int x=p.x,y=p.y;
                        for (int k = 0; k < 4; k++) {
                            int nx=x+dx[k],ny=y+dy[k];
                            if(0<=nx && nx<n && 0<=ny && ny<m && !visited[nx][ny] && map[nx][ny]==0){
                                map[nx][ny]=2;
                                visited[nx][ny]=true;
                                q.add(new Point(nx,ny));
                            }
                        }
                    }

                }
            }
        }
        int cnt=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(map[i][j]==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }

    static void comb(int i,int n,List<Integer> list){

        if(list.size()==3){
            List<Point> wallList=new ArrayList<>();
            for (int a:list) {
                wallList.add(blanks.get(a));
            }
            for(Point p:wallList){
                map[p.x][p.y]=1;
            }
            answer=Math.max(answer,count());
            map= Arrays.stream(tempMap).map(int[]::clone).toArray(int[][]::new);
            return;
        }
        for(int j=i+1;j<n;j++){
            List<Integer> tempList=new ArrayList<>(list);
            tempList.add(j);
            comb(j,n,tempList);
        }
    }
}
class Point{
    int x,y;
    Point(int x,int y){
        this.x=x;
        this.y=y;
    }
}
