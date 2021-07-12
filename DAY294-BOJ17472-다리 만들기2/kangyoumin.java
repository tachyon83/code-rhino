import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] dx = {0,0,1,-1};
    static int[] dy = {1,-1,0,0};
    static int n,m;
    static int[][] map;
    static boolean[][] visited;
    static int island = 0;
    static PriorityQueue<edge> pq = new PriorityQueue<edge>();
    static int result = 0;    
    static int[] parents;
    static int bridge_count = 0;
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] str = br.readLine().split(" ");
        n = Integer.parseInt(str[0]);
        m = Integer.parseInt(str[1]);
        
        map = new int[n][m];
        visited = new boolean[n][m];
        
        for(int i=0; i<n; i++) {
            str = br.readLine().split(" ");
            for(int j=0; j<m; j++) {
                map[i][j] = Integer.parseInt(str[j]);
            }
        }
        
        //bfs를 통해 섬에 번호를 부여한다.
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(map[i][j] == 1 && !visited[i][j]) {
                    island++;
                    bfs(new dot(i,j));
                }
            }
        }
        
        //각 좌표에서 만들 수 있는 최대의 다리를 만든다.
        //다리의 길이는 2이상이어야 하므로, 2 이상이면 pq에 넣어준다.
        visited = new boolean[n][m];
        //show();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(map[i][j] != 0) {
                    makeBridge(new dot(i,j), map[i][j]);
                }
            }
        }
        
        //다리를 다 만들었으면 크루스칼 알고리즘을 실행한다.
        //pq의 간선만큼 반복하면서 사이클을 확인하며 최소 간선의 합을 구한다.
        parents = new int[island+1];
        
        for(int i=0; i<parents.length; i++) {
            parents[i] = i;
        }
        
        int size = pq.size();
        for(int i=0; i<size; i++) {
            edge tmp = pq.poll();
                        
            int a = find(tmp.s);
            int b = find(tmp.e);
            
            if(a==b) continue;
            
            union(tmp.s, tmp.e);
            result += tmp.v;
            bridge_count++;
        }
        //result == 0 이거나 다리의 개수가 섬의 개수 - 1이 아니면 -1을 출력한다.
        if(result == 0 || bridge_count != island-1) {
            System.out.println(-1);
        } else {
            System.out.println(result);
        }
    }
 
    static void bfs(dot d) {
        Queue<dot> q = new LinkedList<dot>();
        visited[d.x][d.y] = true;
        map[d.x][d.y] = island;
        q.add(d);
        
        while(!q.isEmpty()) {
            dot t = q.poll();
            int x = t.x;
            int y = t.y;
            
            for(int i=0; i<4; i++) {
                int x2 = x + dx[i];
                int y2 = y + dy[i];
                
                if(x2>=0 && x2<n && y2>=0 && y2<m && map[x2][y2] == 1 && !visited[x2][y2]) {
                    q.add(new dot(x2,y2));
                    map[x2][y2] = island;
                    visited[x2][y2] = true;
                }
            }
            
        }
    }
    //상하좌우 중 한 방향으로 계속 이동하면서 다른 섬이 나올 때까지 반복한다.
    //중간에 좌표를 넘어가거나, 자신과 같은 번호가 나오면 좌표와 length를 초기화 한후 넘어간다.
    public static void makeBridge(dot d, int num) {
        int x2 = d.x;
        int y2 = d.y;
        int length = 0;
        
        for(int i=0; i<4; i++) {
            while(true) {
                x2 = x2 + dx[i];
                y2 = y2 + dy[i];
                
                if(x2>=0 && x2<n && y2>=0 && y2<m) {
                    if(map[x2][y2] == num) {
                        length = 0;
                        x2 = d.x;
                        y2 = d.y;
                        break;
                    } else if(map[x2][y2] == 0){
                        length++;
                    } else {
                        //1보다 크면 pq에 추가해준다.
                        if(length > 1) {
                            pq.add(new edge(num, map[x2][y2], length));
                        }
                        length = 0;
                        x2 = d.x;
                        y2 = d.y;
                        break;
                    }
                } else {
                    length = 0;
                    x2 = d.x;
                    y2 = d.y;
                    break;
                }
            }
        }
    }
    //크루스칼 알고리즘을 위한 find, union 함수. 
    //외우는게 편하다
    public static int find(int a) {
        if(a == parents[a]) return a;
        parents[a] = find(parents[a]);
        return parents[a];
    }
    
    public static void union(int s,int e) {
        int aRoot = find(s);
        int bRoot = find(e);
        
        if(aRoot != bRoot) {
            parents[aRoot] = e;
        } else {
            return;
        }
    }
}
 
class dot {
    int x;
    int y;
    
    public dot(int x,int y) {
        this.x = x;
        this.y = y ;
    }
}
// 간선 class : value를 기준으로 compareTo를 overriding하였다.
class edge implements Comparable<edge> {
    int s;
    int e;
    int v;
    
    public edge(int s,int e,int v) {
        super();
        this.s = s;
        this.e = e;
        this.v = v;
    }
 
    @Override
    public int compareTo(edge arg0) {
        return arg0.v >= this.v ? -1:1;
    }
}
