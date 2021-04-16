// 연결요소의 개수(silver 2)

// 제출 결과: [메모리: 172460KB 시간: 804ms]
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class BJ_11724 {
    static int[][] map;
    static boolean[] visit;
    static Queue<Integer> q = new LinkedList<>();
    static int n;

    public static void bfs(int start){
        q.add(start);
        visit[start] = true;

        while(!q.isEmpty()){
            int temp = q.poll();

            for (int i = 1; i <= n; i++) {
                if(!visit[i] && map[temp][i]==1){
                    q.add(i);
                    visit[i] = true;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] Input = br.readLine().split(" ");
        n = Integer.parseInt(Input[0]);
        int m = Integer.parseInt(Input[1]);
        map = new int[n+1][n+1];
        visit = new boolean[n+1];
        int count = 0;

        for (int i = 1; i <= m; i++) {
            Input = br.readLine().split(" ");
            map[Integer.parseInt(Input[0])][Integer.parseInt(Input[1])] = 1;
            map[Integer.parseInt(Input[1])][Integer.parseInt(Input[0])] = 1;
        }

        for (int i = 1; i <= n; i++) {
            if(!visit[i]){
                bfs(i);
                count++;
            }
        }

        System.out.println(count);
    }
}
